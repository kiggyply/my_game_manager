#include <iostream>
#include <fstream>
#include "specific_game.h"
#include "EventManager.h"
#include <filesystem>

int main(int argc, char* argv[]) {
    // 获取可执行文件的路径
    std::string executablePath = std::filesystem::absolute(argv[0]).string();

    // 获取项目根目录的路径（即game manager的根目录）
    std::string projectPath = std::filesystem::path(executablePath).parent_path().string();

    // 配置文件路径为项目路径下的config目录
    std::string configPath = projectPath + "\\Config\\";

    // 配置文件路径为项目路径下的database目录
    std::string dbfigPath = projectPath + "\\Database\\";
    
    EventManager eventManager;

    // 事件处理程序
    eventManager.HandleRunGameConfigurations(configPath);
    // eventManager.HandleDataBaseLoad(dbfigPath);
}