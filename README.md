# my_game_manager
本地游戏管理器

# 常用命令：
Remove-Item -Recurse -Force *

git remote add origin git@github.com:kiggyply/my_game_manager.git
git pull git@github.com:kiggyply/my_game_manager.git
git push origin master:main

# 工程编译
cd build
cmake cmake -G "MinGW Makefiles" ..
make install_my_targets