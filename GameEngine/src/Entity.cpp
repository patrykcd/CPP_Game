#include "Entity.h"
#include <utility>

namespace Core {
    EntityWrapperItem::EntityWrapperItem() {

    }

    EntityWrapperItem::EntityWrapperItem(std::string name) {
        SetName(std::move(name));
    }

    EntityWrapperItem::EntityWrapperItem(const char *name) {
        SetName(name);
    }

    std::string EntityWrapperItem::GetName() const {
        return name;
    }

    void EntityWrapperItem::SetName(std::string name) {
        SetName(name.c_str());
    }

    void EntityWrapperItem::SetName(const char *name) {
        this->name = name;
    }
}