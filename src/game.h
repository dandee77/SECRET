#pragma once
#include <memory>
#include "Scene.h"

class Game {
public:
    Game() : currentScene(nullptr) {}
    ~Game() = default;

    void setScene(std::shared_ptr<Scene> scene) {
        currentScene = std::move(scene);
        currentScene->initialize(); // Call initialize on the new scene
    }

    void update(float deltaTime) {
        if (currentScene) {
            currentScene->update(deltaTime);  // Update the current scene
        }
    }

    void draw() const {
        if (currentScene) {
            currentScene->draw();  // Draw the current scene
        }
    }

private:
    std::shared_ptr<Scene> currentScene;
};