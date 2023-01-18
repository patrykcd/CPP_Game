#include "Scene.h"

namespace Core {
    void Scene::AddEntity(const std::shared_ptr<Entity> &entity) {
        entities.push_back(entity);
    }

    void Scene::DeleteEntity(const std::string &name) {
        erase_if(entities, [&name](std::shared_ptr<Entity> &entity) { return entity->GetName() == name; });
    }

    std::shared_ptr<Entity> Scene::GetEntityByName(const std::string &name) {
        auto result = std::find_if(
                entities.begin(),
                entities.end(),
                [&name](std::shared_ptr<Entity> &entity) { return entity->GetName() == name; }
        );

        if (result != entities.end()) {
            return *result;
        } else {
            throw std::runtime_error(std::string(name) + " Entity not found in Scene.");
        }
    }

    size_t Scene::Count() {
        return entities.size();
    }

    std::shared_ptr<Entity> Scene::GetEntityByIndex(size_t index) {
        return entities[index];
    }
}