#include "database.h"
#include <iostream>

// 构造函数，初始化数据库文件路径
Database::Database(const std::string& dbName)
    : dbName_(dbName), db_(nullptr) {}

// 析构函数，关闭数据库连接
Database::~Database() {
    Close();
}

// 打开数据库连接
bool Database::Open() {
    // 尝试打开指定路径的数据库文件
    int result = sqlite3_open(dbName_.c_str(), &db_);
    if (result != SQLITE_OK) {
        std::cerr << "无法打开数据库: " << sqlite3_errmsg(db_) << std::endl;
        return false;
    }
    return true;
}

// 关闭数据库连接
void Database::Close() {
    if (db_) {
        sqlite3_close(db_);
        db_ = nullptr;
    }
}

// 创建名为"GameData"的游戏数据表
bool Database::CreateGameTable() {
    // SQL语句用于创建名为"GameData"的游戏数据表
    const char* createTableSQL = "CREATE TABLE IF NOT EXISTS GameData ("
                                 "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                                 "GameName TEXT NOT NULL,"
                                 "Score INTEGER NOT NULL"
                                 ");";

    char* errMsg = nullptr;
    int result = sqlite3_exec(db_, createTableSQL, nullptr, nullptr, &errMsg);

    if (result != SQLITE_OK) {
        std::cerr << "无法创建表: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }

    return true;
}


bool Database::InsertGameData(const std::string& gameName, int score) {
    // SQL语句用于向"GameData"表插入游戏数据
    std::string insertSQL = "INSERT INTO GameData (GameName, Score) VALUES ('" + gameName + "', " + std::to_string(score) + ");";

    char* errMsg = nullptr;
    int result = sqlite3_exec(db_, insertSQL.c_str(), nullptr, nullptr, &errMsg);

    if (result != SQLITE_OK) {
        std::cerr << "无法插入数据: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }

    return true;
}

void Database::QueryGameData() {
    // SQL语句用于从"GameData"表查询游戏数据
    const char* querySQL = "SELECT GameName, Score FROM GameData;";

    sqlite3_stmt* stmt;
    int result = sqlite3_prepare_v2(db_, querySQL, -1, &stmt, nullptr);

    if (result == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            // 提取查询结果中的游戏名称和分数
            std::string gameName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
            int score = sqlite3_column_int(stmt, 1);

            // 输出查询结果
            std::cout << "游戏名称: " << gameName << ", 分数: " << score << std::endl;
        }
        sqlite3_finalize(stmt);
    }
}