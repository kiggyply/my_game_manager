#include "game_base.h"

GameBase::GameBase(const std::string& gameName) : gameName_(gameName) {
    // 在构造函数中执行其他初始化操作，如果有的话
}

void GameBase::SetSavePath(const std::string& savePath) {
    gameSavePath_ = savePath;
    // 在这里可以执行与 SetSavePath 函数相关的操作
}

void GameBase::SetMapPath(const std::string& mapPath) {
    gameMapPath_ = mapPath;
    // 在这里可以执行与 SetMapPath 函数相关的操作
}

// MapSavePath 函数是纯虚函数，应在子类中提供实现

// 如果有其他成员函数，也需要在这个文件中提供它们的实现
