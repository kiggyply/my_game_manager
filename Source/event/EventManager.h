#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
// #include "database.h"
#include "specific_game.h"

class EventManager {
public:
    void HandleRunGameConfigurations(const std::string& configPath);
    // bool HandleDataBaseLoad(const std::string& dbfigPath);
};

#endif // EVENTMANAGER_H