#include "ImageComponent.h"
#include <utility>
#include <string>

namespace Core::Components {
    ImageComponentWrapperItem::ImageComponentWrapperItem() {
    }

    ImageComponentWrapperItem::ImageComponentWrapperItem(const char *_path) {
        path = std::string_view(std::string(_path));
    }

    std::string_view ImageComponentWrapperItem::getPath() {
        return path;
    }

    ImageComponentWrapperItem::~ImageComponentWrapperItem() {

    }
}