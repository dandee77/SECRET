#pragma once
#include "scene.h"
#include "entityManager.h"
#include "raylib.h"

class GameScene : public Scene {
public:
    void initialize() override {
        // Any initial setup for Game Scene could go here
        entityManager.addEntity(1, {100, 100});
    }

    void update(float deltaTime) override {
        // Game update logic (e.g., player movement, enemy updates) goes here
        entityManager.updateEntities(deltaTime);
    }

    void draw() const override {
        ClearBackground(DARKBLUE); // Render dark blue background
        DrawText("Game Scene", 200, 200, 20, RAYWHITE);
        entityManager.drawEntities();
    }
    
private:
    EntityManager entityManager;
};