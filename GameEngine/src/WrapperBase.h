#pragma once
#include <memory>
#include "WrapperItem.h"

namespace Core {
    class WrapperBase {
    protected:

//        WrapperBase() = default;

//        explicit WrapperBase(std::shared_ptr<WrapperItem> ptr) {
//            this->ptr = ptr;
//        }

//        ~WrapperBase() = default;

    public:
        WrapperBase() {}

        virtual ~WrapperBase() {}

        std::shared_ptr<WrapperItem> ptr;

        inline bool IsValid() const
        {
            return this->ptr != nullptr;
        }

        inline bool IsNull() const
        {
            return !IsValid();
        }

    };
}