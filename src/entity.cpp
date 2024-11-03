#include "entity.h"

Entity::Entity()
{
    this->texture = LoadTexture("assets/placeholder.png");
    this->posX = 0;
    this->posY = 0;
    this->speed = 0;
    
}

Entity::~Entity()
{
    UnloadTexture(texture);
}

void Entity::setTexture(const char* fileName)
{
    UnloadTexture(texture);
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

int Entity::getSpeed() const
{
    return this->speed;
}

void Entity::setPosX(int newValue)
{
    this->posX = newValue;
}

void Entity::setPosY(int newValue)
{
    this->posY = newValue;
}

void Entity::setSpeed(int newValue)
{
    this->speed = newValue;
}