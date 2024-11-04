#pragma once
#include "scene.h"
#include "entityManager.h"
#include "raylib.h"

class GameScene : public Scene {
public:
    void initialize() override {
        // Any initial setup for Game Scene could go here
        for (int i = 0; i < 500; i++) {
            entityManager.addEntity(i, {(float)GetRandomValue(15, GetScreenWidth() - 15), (float)GetRandomValue(15, GetScreenHeight() - 15)});
        }
    }

    void update(float deltaTime) override {
        // Game update logic (e.g., player movement, enemy updates) goes here
        entityManager.updateEntities(deltaTime);
    }

    void draw() const override {
        ClearBackground(DARKGRAY); // Render dark blue background
        DrawText("Press [BACKSPACE] to kill one random ball", 175, 200, 20, RAYWHITE);
        entityManager.drawEntities();
    }
    
private:
    EntityManager entityManager;
};