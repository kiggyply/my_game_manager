#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <sqlite3.h>

class Database {
public:
    // 构造函数，需要提供数据库名称
    Database(const std::string& dbName);
    
    // 析构函数，用于关闭数据库
    ~Database();

    // 打开数据库连接
    bool Open();

    // 关闭数据库连接
    void Close();

    // 创建游戏数据表
    bool CreateGameTable();

    // 插入游戏数据
    bool InsertGameData(const std::string& gameName, int score);

    // 查询游戏数据
    void QueryGameData();

private:
    std::string dbName_;  // 数据库名称
    sqlite3* db_;        // SQLite数据库连接
};

#endif // DATABASE_H