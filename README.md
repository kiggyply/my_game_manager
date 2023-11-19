# my_game_manager
本地游戏管理器

# 常用命令：
Remove-Item -Recurse -Force *

## 指令
git remote add origin git@github.com:kiggyply/my_game_manager.git
git pull git@github.com:kiggyply/my_game_manager.git
git push origin master:main

## 工程编译
cd build
cmake cmake -G "MinGW Makefiles" ..
make install_my_targets

# 待完成功能
1. ui界面（长期ing）
2. 游戏相关信息记录：包括时长计算、最后一次运行时间