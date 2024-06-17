#pragma once

#include <Sk/Math/Matrix.hpp>

namespace Sk {
    struct Translation final : public Matrix3 {
        explicit Translation(float x, float y);
        explicit Translation(const Vector2& t);
    };

    Translation operator*(const Translation& lhs, const Translation& rhs);

    Vector2 getTranslationVector(const Translation& t);
    Translation invert(const Translation& t);

    struct Rotation final : public Matrix3 {
        explicit Rotation(float angle);
    };

    Rotation operator*(const Rotation& lhs, const Rotation& rhs);

    float getAngle(const Rotation& r);
    Rotation invert(const Rotation& r);
}