#include "EntityGroup.h"

namespace Core {
    void EntityGroup::AddEntity(Entity &entity) {
        for (int i = 1;
             std::any_of(
                     entities.begin(),
                     entities.end(),
                     [&](Entity &entityElement) {
                         return entityElement.GetName() == entity.GetName();
                     });
             i++) {
            entity.SetName(entity.GetName() + " (" + std::to_string(i) + ")");
        }
        entities.push_back(entity);
    }

    void EntityGroup::AddEntity(const Entity &entity) {
        AddEntity(const_cast <Entity &>(entity));
    }

    void EntityGroup::DeleteEntity(const std::string &name) {
        erase_if(entities, [&name](Entity &entityElement) { return entityElement.GetName() == name; });
    }

    Entity EntityGroup::GetEntityByName(const std::string &name) {
        auto result = std::find_if(
                entities.begin(),
                entities.end(),
                [&name](Entity &entityElement) { return entityElement.GetName() == name; }
        );

        if (result != entities.end()) {
            return *result;
        } else {
            throw std::runtime_error(std::string(name) + " Entity not found in EntityGroup.");
        }
    }

    size_t EntityGroup::Count() {
        return entities.size();
    }

    Entity EntityGroup::GetEntityByIndex(size_t index) {
        return entities[index];
    }
}