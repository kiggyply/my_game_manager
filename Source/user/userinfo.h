#ifndef USER_INFO_H
#define USER_INFO_H

#include <string>
#include <Windows.h>
#include <filesystem>
#include <string>
using namespace std;

class UserInfo {
public:
    UserInfo();
    char userName[255];
    string projectRootDir;
};

#endif