#include "Entity.h"
#include <utility>
namespace Core {
    Entity::Entity(std::string &name) : name(name) {
    }

    Entity::Entity(const char *name) : name(name) {
    }

    std::string Entity::GetName() const {
        return name;
    }
}