#include "userinfo.h"
using namespace std;

UserInfo::UserInfo() { 
    DWORD size = 255;
    GetUserNameA(userName, &size);
    filesystem::path currentPath = filesystem::current_path();
    projectRootDir = currentPath.string();
}