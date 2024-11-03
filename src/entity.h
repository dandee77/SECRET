#pragma once
#include "raylib.h"

class Entity
{
public:
    Entity();
    ~Entity();
    void setTexture(const char* fileName);
    void Draw();
    //note: the movement will be implemented in each child class
    //insert a setter and getter here
    int getPosX() const;
    int getPosY() const;
    int getSpeed() const;

    void setPosX(int newValue);
    void setPosY(int newValue);
    void setSpeed(int newValue);
private:
    Texture2D texture;
    int posX;
    int posY;
    int speed;
    //insert additional attributes of the entity here
};