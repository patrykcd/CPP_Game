#include "Entity.h"
#include <utility>

namespace Core {
    Entity::Entity() {

    }

    Entity::Entity(std::string name) {
        SetName(std::move(name));
    }

    Entity::Entity(const char *name) {
        SetName(name);
    }

    std::string Entity::GetName() const {
        return name;
    }

    void Entity::SetName(std::string name) {
        SetName(name.c_str());
    }

    void Entity::SetName(const char *name) {
        this->name = name;
    }
}