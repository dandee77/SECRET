#pragma once
#include "Scene.h"
#include "raylib.h"
#include <memory>

class GameScene; // Forward declare GameScene

class MainMenuScene : public Scene {
public:
    void initialize() override {
        // Any initial setup for Main Menu could go here
    }

    void update(float deltaTime) override {
        // Check for Enter key press to switch scenes
        if (IsKeyPressed(KEY_ENTER)) {
            if (onSwitchScene) {
                onSwitchScene(std::static_pointer_cast<Scene>(std::make_shared<GameScene>()));
            }
        }
    }

    void draw() const override {
        ClearBackground(DARKGRAY); // Render dark gray background
        DrawText("Press ENTER to Start Game", 200, 200, 20, RAYWHITE);
    }

    // Callback to allow switching scenes
    std::function<void(std::shared_ptr<Scene>)> onSwitchScene;
};