#pragma once

//#include "Components/TransformComponent.h"
#include <vector>
#include <iostream>
#include <typeinfo>
#include "Components/Component.h"

class Entity {
private:
    std::vector<std::shared_ptr<Component>> components;
public:
    template<typename T, typename... TArgs>
    std::shared_ptr<T> AddComponent(TArgs &&... args) {
        auto newComponent = std::make_shared<T>(std::forward<TArgs>(args)...);
        if (std::any_of(
                components.begin(),
                components.end(),
                [](std::shared_ptr<Component> &c) { return typeid(T) == typeid(*c); })) {
            throw std::runtime_error("Entity already contains " + std::string(typeid(*newComponent).name()) + ".");
        }
        components.push_back(newComponent);
        return newComponent;
    }

    template<typename T>
    void DeleteComponent() {
//        auto result = std::search_n(
//                components.begin(),
//                components.end(), 1,
//                [](std::shared_ptr<Component>& c) { return typeid(T) == typeid(*c); });
//        std::cout <<
    }

    template<typename T>
    std::shared_ptr<T> GetComponent() {
        auto result = std::find_if(
                std::begin(components),
                std::end(components),
                [](std::shared_ptr<Component> &c) { return typeid(T) == typeid(*c); });
        if (result != std::end(components)) {
            return std::dynamic_pointer_cast<T>(*result);
        } else {
            throw std::runtime_error(std::string(typeid(T).name()) + " component not found in entity.");
        }
    }
};
