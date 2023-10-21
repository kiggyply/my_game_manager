#ifndef SPECIFIC_GAME_H
#define SPECIFIC_GAME_H

#include "game_base.h"

class SpecificGame : public GameBase {
public:
    SpecificGame(const std::string& gameName);
    bool MapSavePath() override;
};

#endif // SPECIFIC_GAME_H