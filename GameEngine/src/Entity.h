#pragma once

#include <vector>
#include <iostream>
#include <typeinfo>
//#include <memory>
#include <Components/Component.h>
#include "Wrapper.h"

namespace Core {
    using namespace Components;
    namespace Impl {
        class Entity : public WrapperItem {
        public:
            Entity();

            Entity(std::string name);

            Entity(const char *name);

            std::string GetName() const;

            void SetName(std::string name);

            void SetName(const char *name);

            template<typename T, typename... TArgs>
            std::shared_ptr<T> AddComponent(TArgs &&... args) {
                auto newComponent = std::make_shared<T>(std::forward<TArgs>(args)...);
                if (std::any_of(
                        components.begin(),
                        components.end(),
                        [this](std::shared_ptr<Component> &c) { return isType<T>(*c); })) {
                    throw std::runtime_error(
                            "Entity already contains " + std::string(typeid(*newComponent).name()) + ".");
                }
                components.push_back(newComponent);
                return newComponent;
            }

            template<typename T>
            void DeleteComponent() {
                erase_if(components, [this](std::shared_ptr<Component> &c) { return isType<T>(*c); });
            }

            template<typename T>
            std::shared_ptr<T> GetComponent() {
                auto result = std::find_if(
                        components.begin(),
                        components.end(),
                        [this](std::shared_ptr<Component> &c) { return isType<T>(*c); });
                if (result != components.end()) {
                    return std::dynamic_pointer_cast<T>(*result);
                } else {
                    throw std::runtime_error(std::string(typeid(T).name()) + " Component not found in Entity.");
                }
            }

        private:
            std::vector<std::shared_ptr<Component>> components;
            std::string name;

            template<typename T>
            bool isType(Component &c) { return typeid(T) == typeid(c); }
        };
    }
    using Entity = Wrapper<Impl::Entity>;
}


