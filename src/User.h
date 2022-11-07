#pragma once
#include "Player.h"

class User : public Player
{
public:
    User() : Player() {};
    void changePosition();
private:
    int prevY = posY;
};