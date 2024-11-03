#pragma once
#include "entity.h"
#include <unordered_map>
#include <memory>

class EntityManager {
public:
    // Adds an entity to the manager
    std::shared_ptr<Entity> addEntity(int id, Vector2 position) {
        auto entity = std::make_shared<Entity>(id, position);
        entities[id] = entity;
        return entity;
    }

    // Removes an entity by ID
    void removeEntity(int id) {
        entities.erase(id);
    }

    // Update all entities
    void updateEntities(float deltaTime) {
        for (auto it = entities.begin(); it != entities.end();) {
            auto& entity = it->second;
            entity->update(deltaTime);

            // Remove entities marked for deletion
            if (entity->getHealth() <= 0) {
                if (entity->onDeath()) it = entities.erase(it); // Remove and advance iterator
            } else {
                ++it;
            }
        }
    }

    // Draw all entities
    void drawEntities() const {
        for (const auto& [id, entity] : entities) {
            entity->draw();
        }
    }

    // Retrieve an entity by ID
    std::shared_ptr<Entity> getEntity(int id) const {
        auto it = entities.find(id);
        if (it != entities.end()) {
            return it->second;
        }
        return nullptr;
    }

private:
    std::unordered_map<int, std::shared_ptr<Entity>> entities;
};