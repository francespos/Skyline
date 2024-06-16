#include <Sk/Math/Translation.hpp>

namespace Sk {
    Translation::Translation(float x, float y) 
        : Matrix3{1.0f, 0.0f, x
        , 0.0f, 1.0f, y
        , 0.0f, 0.0f, 1.0f} {}

    Translation::Translation(const Vector2& t)
        : Matrix3{1.0f, 0.0f, t(0)
        , 0.0f, 1.0f, t(1)
        , 0.0f, 0.0f, 1.0f} {}

    Vector2 Translation::getTranslationVector() const {
        Vector2 ret{v[2], v[5]};
        return ret;
    }

    Translation operator*(const Translation& lhs, const Translation& rhs) {
        Translation ret{lhs.getTranslationVector() + rhs.getTranslationVector()};
        return ret;
    }

    Translation invert(const Translation& t) {
        Translation ret{t};

        ret(0, 2) = -ret(0, 2);
        ret(1, 2) = -ret(1, 2);

        return ret;
    }
}