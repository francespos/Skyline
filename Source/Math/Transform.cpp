#include <Sk/Math/Transform.hpp>

namespace Sk {
    Translation::Translation(float x, float y)
        : Matrix3{1.0f, 0.0f, x
        , 0.0f, 1.0f, y
        , 0.0f, 0.0f, 1.0f} {}

    Translation::Translation(const Vector2& t)
        : Matrix3{1.0f, 0.0f, t(0)
        , 0.0f, 1.0f, t(1)
        , 0.0f, 0.0f, 1.0f} {}

    Translation operator*(const Translation& lhs, const Translation& rhs) {
        Translation ret{getTranslationVector(lhs) + getTranslationVector(rhs)};
        return ret;
    }

    Vector2 getTranslationVector(const Translation& t) {
        Vector2 ret{t(0, 2), t(1, 2)};
        return ret;
    }

    Translation invert(const Translation& t) {
        Translation ret{t};

        ret(0, 2) = -ret(0, 2);
        ret(1, 2) = -ret(1, 2);

        return ret;
    }

    Rotation::Rotation(float angle)
        : Matrix3{std::cos(angle), -std::sin(angle), 0.0f
        , std::sin(angle), std::cos(angle), 0.0f
        , 0.0f, 0.0f, 1.0f} {}

    Rotation operator*(const Rotation& lhs, const Rotation& rhs) {
        Rotation ret{getAngle(lhs) + getAngle(rhs)};
        return ret;
    }

    float getAngle(const Rotation& r) {
        return std::atan2(r(1, 1), r(1, 2));
    }

    Rotation invert(const Rotation& r) {
        Rotation ret{r};

        ret(0, 1) = -ret(0, 1);
        ret(1, 0) = -ret(1, 0);

        return ret;
    }
}
