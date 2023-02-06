#pragma once

#include "Component.h"
#include <string_view>

namespace Core::Components {
    class ImageComponentWrapperItem : public ComponentWrapperItem {
    public:
        ImageComponentWrapperItem();

        ImageComponentWrapperItem(const char *_path);

        std::string_view getPath();

        virtual ~ImageComponentWrapperItem();

    private:
        std::string_view path;
    };

    using ImageComponent = Wrapper<ImageComponentWrapperItem>;
}