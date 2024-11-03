#pragma once
#include <vector>
#include <memory>
#include "stateMachine.h"

class GameObject {
public:
    virtual ~GameObject() = default;
    virtual void update(float deltaTime) = 0;
    virtual void draw() = 0;
};


class Scene {
public:
    virtual ~Scene() = default;

    virtual void initialize() = 0; // Load initial objects or setup
    virtual void update(float deltaTime) {
        for (auto& obj : objects) {
            obj->update(deltaTime);
        }
    }

    virtual void draw() const {
        for (const auto& obj : objects) {
            obj->draw();
        }
    }

protected:
    void addObject(std::shared_ptr<GameObject> obj) {
        objects.emplace_back(std::move(obj));
    }

    std::vector<std::shared_ptr<GameObject>> objects;
};