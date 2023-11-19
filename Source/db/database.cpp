#include "database.h"

using namespace std;

SQLiteDB::SQLiteDB(const string* dbName) : db(nullptr), dbPath(dbName), errMsg(nullptr) {}

SQLiteDB::~SQLiteDB() {
    closeDB();
};

bool SQLiteDB::openDB() {
    int rc = sqlite3_open(dbPath->c_str(), &db);
    if (rc) {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return false;
    } else {
        cout << "Opened database successfully" << endl;
        return true;
    }
};

void SQLiteDB::closeDB() {
    if (db) {
        sqlite3_close(db);
    }
}

const char* SQLiteDB::getSavePathByName(const string gn) {
    const char* game_name = gn.c_str();
    sqlite3_stmt* stmt;
    const char* selectSQL = "SELECT save_path FROM GAME WHERE game_name = ?";
    int rc = sqlite3_prepare_v2(db, selectSQL, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return nullptr;
    }
    rc = sqlite3_bind_text(stmt, 1, game_name, -1, SQLITE_STATIC);
    // 表示sql查询成功
    if (rc == SQLITE_OK) {
        rc = sqlite3_step(stmt);
        // 结果集中有一行数据可用
        if (rc == SQLITE_ROW) {
            const char* result = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
            return result;
        }
    }
    return nullptr;
};

int SQLiteDB::callback(void* data, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        std::cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << std::endl;
    }
    std::cout << "------------------------" << std::endl;
    return 0;
};