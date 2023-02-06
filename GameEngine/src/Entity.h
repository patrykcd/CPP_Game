#pragma once

#include <vector>
#include <iostream>
#include <typeinfo>
#include <Components/Component.h>
#include <Wrapper.h>

namespace Core {
    using namespace Components;

    class EntityWrapperItem : public WrapperItem {
    public:
        EntityWrapperItem();

        EntityWrapperItem(std::string name);

        EntityWrapperItem(const char *name);

        std::string GetName() const;

        void SetName(std::string name);

        void SetName(const char *name);

        template<typename T, typename... TArgs>
        T AddComponent(TArgs &&... args) {
            T newComponent = T::Create(std::forward<TArgs>(args)...);
            if (std::any_of(
                    components.begin(),
                    components.end(),
                    [this](Component &c) { return c.Is<T>(); })) {
                throw std::runtime_error(
                        "Entity already contains " + std::string(typeid(newComponent).name()) + ".");
            }
            components.push_back(newComponent);
            return newComponent;
        }

        template<typename T>
        void DeleteComponent() {
            erase_if(components, [this](Component &c) { return c.Is<T>(); });
        }

        template<typename T>
        T GetComponent() {
            auto result = std::find_if(
                    components.begin(),
                    components.end(),
                    [this](Component &c) { return c.Is<T>(); });
            if (result != components.end()) {
                //return std::dynamic_pointer_cast<T>(*result);
                return *result;
            } else {
                throw std::runtime_error(std::string(typeid(T).name()) + " Component not found in Entity.");
            }
        }

    private:
        std::vector<Component> components;
        std::string name;
    };

    using Entity = Wrapper<EntityWrapperItem>;
}


