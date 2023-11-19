#ifndef DATA_BASE_H
#define DATA_BASE_H
#include <iostream>
#include <string>
#include "sqlite/sqlite3.h"
using namespace std;

class SQLiteDB  {
public:
    SQLiteDB(const string* dbPath);   
    ~SQLiteDB();
    bool openDB();
    void closeDB();
    const char* getSavePathByName(const string);
    sqlite3* db;
    const string* dbPath;
    char* errMsg;
private:
    static int callback(void* data, int argc, char** argv, char** azColName);
};

#endif