#include "ImageComponent.h"
#include <utility>
#include <string>

namespace Core::Components {
    ImageComponent::ImageComponent() {
    }

    ImageComponent::ImageComponent(const char *_path) {
        path = std::make_shared<std::string_view>(std::string_view(std::string(_path)));
    }

    std::shared_ptr<std::string_view> ImageComponent::getPath() {
        return path;
    }

    ImageComponent::~ImageComponent() {

    }
}