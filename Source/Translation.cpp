#include <SkMath/Translation.hpp>

namespace Sk {
    Translation::Translation(float x, float y) : x{x}, y{y} {}

    Translation& Translation::invert() {
        *this = invert(*this);
        return *this;
    }

    Translation invert(const Translation& t) {
        Translation ret{-t.x, -t.y};
        return ret;
    }
}
