#include "player.h"

Player::Player()
{
    setSpeed(5);
}

void Player::Move()
{
    if(IsKeyDown(KEY_UP))
    {
        setPosY(getPosY() - getSpeed());
    }
    if(IsKeyDown(KEY_DOWN))
    {
        setPosY(getPosY() + getSpeed());
    }
    if(IsKeyDown(KEY_RIGHT))
    {
        setPosX(getPosX() + getSpeed());    
    }
    if(IsKeyDown(KEY_LEFT))
    {
        setPosX(getPosX() - getSpeed());
    }
}