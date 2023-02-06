#include "EntityGroup.h"

namespace Core {
    void EntityGroupWrapperItem::AddEntity(const Entity& entity) {
        for (int i = 1;
             std::any_of(
                     entities.begin(),
                     entities.end(),
                     [&](const Entity& entityElement) {
                         return entityElement->GetName() == entity->GetName();
                     });
             i++) {
            entity->SetName(entity->GetName() + " (" + std::to_string(i) + ")");
        }
        entities.push_back(entity);
    }

    void EntityGroupWrapperItem::DeleteEntity(const std::string &name) {
        erase_if(entities, [&name](const Entity& entityElement) { return entityElement->GetName() == name; });
    }

    Entity EntityGroupWrapperItem::GetEntityByName(const std::string &name) {
        auto result = std::find_if(
                entities.begin(),
                entities.end(),
                [&name](const Entity& entityElement) { return entityElement->GetName() == name; }
        );

        if (result != entities.end()) {
            return *result;
        } else {
            throw std::runtime_error(std::string(name) + " Entity not found in EntityGroup.");
        }
    }

    size_t EntityGroupWrapperItem::Count() {
        return entities.size();
    }

    Entity EntityGroupWrapperItem::GetEntityByIndex(size_t index) {
        return entities[index];
    }
}