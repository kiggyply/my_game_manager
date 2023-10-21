#ifndef GAME_BASE_H
#define GAME_BASE_H

#include <string>

class GameBase {
public:
    GameBase(const std::string& gameName);
    void SetSavePath(const std::string& savePath);
    void SetMapPath(const std::string& mapPath);
    virtual bool MapSavePath() = 0;

protected:
    std::string gameName_;
    std::string gameSavePath_;
    std::string gameMapPath_;
};

#endif // GAME_BASE_H