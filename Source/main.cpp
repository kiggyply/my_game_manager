#include <iostream>
#include <Windows.h>
#include "evenmanager.h"
using namespace std;

int main() {
    // 设置控制台
    SetConsoleOutputCP(65001); // 设置为 UTF-8 编码
    ExeInit init = ExeInit();
    init.globalInit();
}