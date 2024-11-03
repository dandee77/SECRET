#pragma once
#include "raylib.h"

class Entity
{
public:
    Entity();
    void setTexture(const char* fileName);
    void Draw();
    void Update(); // for movement
    //insert a setter and getter here
    int getPosX() const;
    int getPosY() const;

    void setPosX(int newValue);
    void setPosY(int newValue);
private:
    Texture2D texture;
    int posX;
    int posY;
    //insert additional attributes of the entity here
};