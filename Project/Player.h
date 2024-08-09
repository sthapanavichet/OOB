//
// Created by Sthapanavichet on 7/23/2023.
//

#ifndef PROJECT_PLAYER_H
#define PROJECT_PLAYER_H
#include <string>

class PlayerBase {
    std::string name;
    double cash;
    int sumDependantCards;
public:
    PlayerBase();
    PlayerBase(std::string);
    PlayerBase(const PlayerBase&);
    PlayerBase operator=(const PlayerBase&);
    void SetName(std::string);
    std::string GetName(void);
    void SetDependentCards(int);
    void AddDependentCards(void);
    int SumDependentCards(void);
    void AddCash(int);
    int GetCash(void);
    ~PlayerBase();
    bool operator==(const PlayerBase&);
    bool operator> (const PlayerBase&);
    bool operator< (const PlayerBase&);
    PlayerBase& operator<<(int);
    PlayerBase& operator>>(int);
};



#endif //PROJECT_PLAYER_H
