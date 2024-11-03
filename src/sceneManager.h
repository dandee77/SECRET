#pragma once
#include "Scene.h"
#include "StateMachine.h"

class SceneManager : public StateMachine<SceneManager> {
public:
    SceneManager() {
        registerState(MainMenuSceneID, []() { return std::make_shared<MainMenuScene>(); });
        registerState(GameSceneID, []() { return std::make_shared<GameScene>(); });
    }

    void update(float deltaTime) {
        StateMachine<SceneManager>::update(this, deltaTime); // Update current scene
    }

    void loadScene(int sceneID) {
        changeState(sceneID, this);
    }

private:
    enum SceneIDs {
        MainMenuSceneID = 0,
        GameSceneID
    };
};