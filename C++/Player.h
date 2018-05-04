#ifndef PLAYER_H
#define PLAYER_H

#include "Game.h"
#include <iostream>

class Player
{
    public:
        Player(std::string playerName);
        int getPlace();
        int getPurse();
        std::string getName();
        bool isInPenaltyBox();
        void step(int roll);
        void addCoin();
        void sendToPenaltyBox();
        void getOutOfPenaltyBox();
    private:
        std::string name;
        int place;
        int purse;
        bool inPenaltyBox;
};

#endif /* PLAYER_H */