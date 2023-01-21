#pragma once
#include <vector>
#include <memory>
#include "Entity.h"
namespace Core {
    class EntityGroup {
    public:
        void AddEntity(Entity &entity);

        void AddEntity(const Entity &entity);

        void DeleteEntity(const std::string &name);

        Entity GetEntityByName(const std::string &name);

        size_t Count();

        Entity GetEntityByIndex(size_t index);

    private:
        std::vector<Entity> entities;
    };
}