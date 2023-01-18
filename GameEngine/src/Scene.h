#pragma once
#include <vector>
#include <memory>
#include "Entity.h"
namespace Core {
    class Scene {
    public:
        void AddEntity(const std::shared_ptr<Entity> &entity);

        void DeleteEntity(const std::string &name);

        std::shared_ptr<Entity> GetEntityByName(const std::string &name);

        size_t Count();

        std::shared_ptr<Entity> GetEntityByIndex(size_t index);

    private:
        std::vector<std::shared_ptr<Entity>> entities;
    };
}