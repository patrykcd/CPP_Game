#pragma once

#include "Wrapper.h"

namespace Core::Components {
    class ComponentWrapperItem : public WrapperItem {
    public:
        virtual ~ComponentWrapperItem() override {};
    };

    using Component = Wrapper<ComponentWrapperItem>;
}
