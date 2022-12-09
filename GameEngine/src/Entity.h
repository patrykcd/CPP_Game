#pragma once

#include <vector>
#include <iostream>
#include <typeinfo>
#include <memory>
#include "Components/Component.h"

class Entity {
public:
    template<typename T, typename... TArgs>
    std::shared_ptr<T> AddComponent(TArgs &&... args) {
        auto newComponent = std::make_shared<T>(std::forward<TArgs>(args)...);
        if (std::any_of(
                components.begin(),
                components.end(),
                [this](std::shared_ptr<Component> &c) { return isType<T>(*c); })) {
            throw std::runtime_error("Entity already contains " + std::string(typeid(*newComponent).name()) + ".");
        }
        components.push_back(newComponent);
        return newComponent;
    }

    template<typename T>
    void DeleteComponent() {
        auto result = std::find_if(
                components.begin(),
                components.end(),
                [this](std::shared_ptr<Component> &c) { return isType<T>(*c); });
        components.erase(result);
    }

    template<typename T>
    std::shared_ptr<T> GetComponent() {
        auto result = std::find_if(
                components.begin(),
                components.end(),
                [this](std::shared_ptr<Component> &c) { return isType<T>(*c); });
        if (result != std::end(components)) {
            return std::dynamic_pointer_cast<T>(*result);
        } else {
            throw std::runtime_error(std::string(typeid(T).name()) + " component not found in entity.");
        }
    }

private:
    std::vector<std::shared_ptr<Component>> components;

    template<typename T>
    bool isType(Component &c) { return typeid(T) == typeid(c); }
};
