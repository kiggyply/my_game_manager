#include "EventManager.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void EventManager::HandleRunGameConfigurations(const std::string& configPath) {
    // 读取配置文件
    std::cout << configPath + "config.json" << std::endl;
    std::ifstream configFile(configPath + "config.json");
    configFile.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
    json config = json::parse(configFile);

    // 循环遍历每个游戏配置并创建符号链接
    for (auto it = config.begin(); it != config.end(); ++it) {
        std::string gameName = it.key();

        SpecificGame game(gameName);
        game.SetSavePath(it.value()["save_path"]);
        game.SetMapPath(it.value()["map_path"]);

        game.MapSavePath();
    }
}

// bool EventManager::HandleDataBaseLoad(const std::string& dbfigPath) {
//     std::string dbName = dbfigPath + "mygame.db";  // 设置数据库文件路径

//     if (std::ifstream(dbName.c_str()))
//     {
//         // 数据库文件已存在，尝试连接
//         Database db(dbName);  // 移到这里

//         if (db.Open()) {
//             std::cout << "成功打开数据库" << std::endl;
//             // 连接成功后，可以在这里添加其他数据库操作逻辑
//             db.Close();
//             return true;  // 返回加载成功
//         } else {
//             std::cerr << "无法打开数据库" << std::endl;
//         }
//     } else {
//         // 数据库文件不存在，创建并连接
//         Database db(dbName);  // 移到这里

//         if (db.Open()) {
//             std::cout << "成功创建并打开数据库" << std::endl;
//             // 创建数据库表
//             if (db.CreateGameTable()) {
//                 std::cout << "游戏数据表创建成功" << std::endl;
//                 // 创建表成功后，可以在这里添加其他数据库操作逻辑
//                 db.Close();
//                 return true;  // 返回加载成功
//             } else {
//                 std::cerr << "无法创建游戏数据表" << std::endl;
//             }
//         } else {
//             std::cerr << "无法创建或打开数据库" << std::endl;
//         }
//     }
//     return false;  // 返回加载失败
// }