#pragma once

#include "Component.h"
#include <string_view>

namespace Core::Components {
    class ImageComponent : public Component {
    public:
        ImageComponent();

        ImageComponent(const char *_path);

        std::shared_ptr<std::string_view> getPath();

        ~ImageComponent() override;

    private:
        std::shared_ptr<std::string_view> path;
    };
}