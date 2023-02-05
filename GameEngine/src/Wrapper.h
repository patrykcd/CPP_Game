#pragma once

#include <string>
#include "WrapperBase.h"

namespace Core {
    template<typename Impl>
    class Wrapper : public WrapperBase {
    public:
        using ImplType = Impl;
        using Type = Wrapper;

        template<typename ...TArgs>
        static Type Create(TArgs &&... args) {
            Type object;
            object.ptr = std::make_shared<ImplType>(std::forward<TArgs>(args)...);
            return object;
        }

        Wrapper() : WrapperBase() {}

// NOLINTNEXTLINE(google-explicit-constructor)
        Wrapper(WrapperBase const &type) /*: WrapperBase(type)*/ {
            if (type.IsNull()) {
                throw std::runtime_error(std::string("Bad Cast to ") + typeid(ImplType).name());
            }

            ptr = type.ptr;
        }

        template<typename T>
        bool Is() {
            return dynamic_cast<typename T::ImplType *>(GetImpl()) != nullptr;
        }

        ImplType &operator*() const {
            if (IsNull()) {
                throw std::runtime_error(
                        std::string("Can't use operator*. ") + typeid(ImplType).name() + std::string(" is NULL")
                );
            }
            return *GetImpl();
        }

        ImplType *operator->() const {
            if (IsNull()) {
                throw std::runtime_error(
                        std::string("Can't use operator->. ") + typeid(ImplType).name() + std::string(" is NULL")
                );
            }
            return GetImpl();
        }

        ~Wrapper() = default;

    private:
        ImplType *GetImpl() const {
            return std::dynamic_pointer_cast<ImplType>(ptr).get();
        }

        using WrapperBase::ptr;
    };
}