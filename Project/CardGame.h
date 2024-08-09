//
// Created by Sthapanavichet on 7/27/2023.
//

#ifndef PROJECT_CARDGAME_H
#define PROJECT_CARDGAME_H
#include "Player.h"
enum class GameMode {
    HighDefinition,
    LowDefinition
};
template <typename T>
class CardGame {
    const int MAX = 21;
    const int NUM = 2;
    PlayerBase* Player[2];
    bool gameStatus;

public:
    CardGame(GameMode);
    void run();
};

#endif //PROJECT_CARDGAME_H
