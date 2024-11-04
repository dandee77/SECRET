#pragma once
#include "stateMachine.h"
#include "raylib.h"
#include <memory>
#include <string>
#include <iostream>
#include <raymath.h>

class Entity : public StateMachine<Entity> {
public:
    Entity(int id, Vector2 position)
        : id(id), position(position), health(100), velocity({300, 300}) {
            Color colors[] = {RED, BLUE, GREEN, YELLOW, ORANGE, PURPLE, PINK, SKYBLUE, LIME, BEIGE, BROWN, DARKGRAY, MAROON, GOLD, VIOLET, DARKGREEN};
            int index = GetRandomValue(0, 15);
            this->color = colors[index];
            temp = GetRandomValue(0, 1); //delete later
        }

    virtual ~Entity() = default;

    int getId() const { return id; }
    Vector2 getPosition() const { return position; }

    // Update the entity's state and behavior
    void update(float deltaTime) {
        // Call the StateMachine's update to handle state-specific logic
        StateMachine<Entity>::update(this, deltaTime); // e.g., idle, moving, attacking, etc.

        if (temp) position = Vector2Add(position, Vector2Scale(velocity, deltaTime));
        else position = Vector2Subtract(position, Vector2Scale(velocity, deltaTime));

        if (position.x >= GetScreenWidth() - 15 || position.x <= 15) velocity.x *= -1;
        if (position.y >= GetScreenHeight() - 15 || position.y <= 15) velocity.y *= -1;

        if (IsKeyPressed(KEY_BACKSPACE) && id == GetRandomValue(0, 499)) health = 0; // Simulate entity death
    }

    int getHealth() const { return health; }

    // Draw the entity (this can be customized per entity type)
    virtual void draw() const {
        DrawCircleV(position, 10, color); // Draws a simple circle as a placeholder
    }

    bool onDeath() { // Returns true if entity is dead
        std::cout << "Entity " << id << " has died.\n";
        return true;
    }

private:
    int id; 
    Vector2 position;
    int health;
    Vector2 velocity; // Each entity now has its own independent velocity
    Color color;
    int temp;
};
