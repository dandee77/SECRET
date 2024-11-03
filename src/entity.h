#pragma once
#include "stateMachine.h"
#include "raylib.h"
#include <memory>
#include <string>
#include <iostream>

class Entity : public StateMachine<Entity> {
public:
    Entity(int id, Vector2 position)
        : id(id), position(position), health(100) {}

    virtual ~Entity() = default;

    int getId() const { return id; }
    Vector2 getPosition() const { return position; }

    // Update the entity's state and behavior
    void update(float deltaTime) {
        // Call the StateMachine's update to handle state-specific logic
        StateMachine<Entity>::update(this, deltaTime); // ex. idle, moving, attacking, etc..

        // Update common entity logic here (demo purposes)
        if (IsKeyDown(KEY_RIGHT)) position.x += 1;
        if (IsKeyDown(KEY_LEFT)) position.x -= 1;
        if (IsKeyDown(KEY_UP)) position.y -= 1;
        if (IsKeyDown(KEY_DOWN)) position.y += 1;
        if (IsKeyPressed(KEY_BACKSPACE)) health = 0; // Simulate entity death
    }

    int getHealth() const { return health; }

    // Draw the entity (this can be customized per entity type)
    virtual void draw() const {
        DrawCircleV(position, 10, RED); // Draws a simple circle as a placeholder
    }

    bool onDeath() { //returns true if entity is dead
        // Handle death logic (e.g., transition to dead state)
        std::cout << "Entity " << id << " has died.\n";
        // Additional death handling could go here
        return true;
    }

private:
    int id; 
    Vector2 position;
    int health;
};
