#include "evenmanager.h"
using namespace std;
namespace fs = std::filesystem;

void ExeInit::globalInit(){
    // 初始化数据库
    SetDllDirectoryW(L"I:/MyGames/Binaries");
    UserInfo userInfo = UserInfo();
    string dbPath = userInfo.projectRootDir + "/DataBase/game.db";
    SQLiteDB db = SQLiteDB(&dbPath);
    db.openDB();
    // 获得本地游戏库列表
    vector<string> gameLists = getLocGameLists(&userInfo.projectRootDir);
    for (const auto& gameName : gameLists) {
        // 获得游戏的存档路径
        string gameSavePath = getGameSavePath(userInfo, db, gameName);
        cout << "游戏存档路径" << gameSavePath << endl;
        if (gameSavePath.empty()) {
            continue;
        }
        // 进行游戏路径映射
        MapSavePath(userInfo, gameSavePath, gameName);
    }
};

bool MapSavePath(UserInfo userInfo, string gameSavePath, string gameName) {
    // 组合新的游戏存档目录
    const string& newGameSavePath = userInfo.projectRootDir + "/Saves/" + gameName;
    // 判断游戏的存档路径是否已经映射 | 判断project/save/gamename是否为空
    if (fs::exists(newGameSavePath) 
        && fs::is_directory(newGameSavePath) 
        && ! fs::is_empty(newGameSavePath)) {
        cout << gameName << "游戏目录已经映射" << endl;
        return true;
    }
    // 如果新的游戏存档路径不存在，先创建
    try {
        fs::create_directories(newGameSavePath);
    } catch (const std::exception& e) {
        std::cerr << "目录创建失败: " << e.what() << std::endl;
    }
    // 如果原游戏存档存在内容，将其移动到新存档目录下
    PathMove(gameSavePath, newGameSavePath);
    // 创建软链接
    string mklinkCommand = "mklink /D \"" + gameSavePath + "\" \"" + newGameSavePath + "\"";
    int result = std::system(mklinkCommand.c_str());
    if (result == 0) {
        std::cout << "游戏 " << gameName << " 的符号链接创建成功!" << std::endl;
        return true;
    } else {
        std::cerr << "游戏 " << gameName << " 的符号链接创建失败!" << std::endl;
        return false;
    }
    return false;
};

string getGameSavePath(UserInfo userInfo, SQLiteDB db, string gameName) {
    const char* res = db.getSavePathByName(gameName);
    if (res == nullptr) {
        // cout << "数据库中没有收录到这个游戏: " << gameName << endl;
        return "";
    }
    string gameSavePath(res);
    size_t pos = gameSavePath.find("{username}");
    // 处理gameSavePath，将计算机用户名替换进去
    if (pos != string::npos) {        
        // 替换目标子串
        gameSavePath.replace(pos, string("{username}").length(), userInfo.userName);
        cout << gameName << "的存档路径是：" << gameSavePath << endl;
        return gameSavePath;
    }
    // 处理存档是直接在游戏内的相对路径的情况
    pos = gameSavePath.find("{gameRelatePath}");
    if (pos != string::npos) {
        // 将子串{gameRelatePath}替换为project/Games/
        gameSavePath.replace(pos, string("{gameRelatePath}").length(), userInfo.projectRootDir + "/Games");
        cout << gameName << "的存档路径是：" << gameSavePath << endl;
    }
    return gameSavePath;
};

vector<string> getLocGameLists(const string* projectRootDir) {
    string GameRootDir = *projectRootDir + "/Games";
    cout << "本地游戏库路径:" << GameRootDir << endl;
    vector<string> gameLists;
    try {
        for (const auto& entry : filesystem::directory_iterator(GameRootDir)){
            if (entry.is_directory()) {
                gameLists.push_back(entry.path().filename().string());
            }
        }
        for (const auto& dir : gameLists) {
            cout << "本地游戏库列表: " << dir << endl;
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error accessing directory: " << e.what() << std::endl;
    }
    return gameLists;
};