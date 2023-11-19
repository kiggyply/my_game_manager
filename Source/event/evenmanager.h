#ifndef EVEN_MANAGER_H
#define EVEN_MANAGER_H

#include <iostream>
#include <vector>
#include <filesystem>
#include "sqlite/sqlite3.h"
#include "userinfo.h"
#include "database.h"

using namespace std;
class ExeInit{
public:
    void globalInit();
};

// 对游戏存档进行映射
bool MapSavePath(UserInfo userInfo, string gameSavePath, string gameName);

// 获得当前路径下的文件列表
vector<string> getLocGameLists(const string* projectRootDir);

// 根据游戏名从数据库中获得对应存档路径
string getGameSavePath(UserInfo obj, SQLiteDB db, string gameName);

// 目录内容移动
bool PathMove(string oldPath, string newPath);

bool judgeCopyByTime(const string& sourceFile, const string& destinationFile);

#endif