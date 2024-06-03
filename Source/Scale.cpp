#include <SkMath/Scale.hpp>

namespace Sk {
    Scale::Scale(float x, float y) : x{x}, y{y} {}

    Scale& Scale::invert() {
        *this = invert(*this);
        return *this;
    }

    Scale invert(const Scale& s) {
        Scale ret{1.0f / s.x, 1.0f / s.y};
        return ret;
    }
}
