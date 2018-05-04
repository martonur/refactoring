#include "Player.h"

Player::Player(std::string playerName) : name(playerName), place(0), purse(0), inPenaltyBox(false) {}

void Player::step(int roll)
{
    int size = 12;
    place += roll;
    if(place > size - 1)
    {
        place -= size;
    }
}

void Player::addCoin()
{
    purse++;
}

void Player::sendToPenaltyBox()
{
    inPenaltyBox = true;
}

void Player::getOutOfPenaltyBox()
{
	inPenaltyBox = false;
}

std::string Player::getName()
{
    return name;
}

int Player::getPlace()
{
    return place;
}

int Player::getPurse()
{
    return purse;
}

bool Player::isInPenaltyBox()
{
    return inPenaltyBox;
}