#include "entity.h"

Entity::Entity()
{
    this->texture = LoadTexture("assets/placeholder.png");
    this->posX = 0;
    this->posY = 0;
    
}

void Entity::setTexture(const char* fileName)
{
    this->texture = LoadTexture(fileName);
}

void Entity::Draw()
{
    DrawTexture(texture, posX, posY, WHITE);
}

int Entity::getPosX() const
{
    return this->posX;
}

int Entity::getPosY() const
{
    return this->posY;
}

void Entity::setPosX(int newValue)
{
    this->posX = newValue;
}

void Entity::setPosY(int newValue)
{
    this->posY = newValue;
}