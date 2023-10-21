#include "specific_game.h"
#include <cstdlib>
#include <iostream>
#include <filesystem> // 引入文件系统头文件

SpecificGame::SpecificGame(const std::string& gameName)
    : GameBase(gameName) {}

bool SpecificGame::MapSavePath() {
    if (gameMapPath_.empty() || gameSavePath_.empty()) {
        std::cerr << "未设置存档路径或映射路径，符号链接创建失败!" << std::endl;
        return false;
    }
    
    // 在创建符号链接之前检查gameSavePath是否已存在
    if (std::filesystem::exists(gameSavePath_)) {
        std::cerr << "gameSavePath已存在，现进行删除" << std::endl;
        std::string rmdirCommand = "rmdir /s /q \"" + gameSavePath_ + "\"";
        int rmdirResult = std::system(rmdirCommand.c_str());
    }
    std::string mklinkCommand = "mklink /D \"" + gameSavePath_ + "\" \"" + gameMapPath_ + "\"";
    int result = std::system(mklinkCommand.c_str());

    if (result == 0) {
        std::cout << "游戏 " << gameName_ << " 的符号链接创建成功!" << std::endl;
        return true;
    } else {
        std::cerr << "游戏 " << gameName_ << " 的符号链接创建失败!" << std::endl;
        return false;
    }
    return false;
}