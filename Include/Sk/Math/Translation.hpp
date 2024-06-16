#pragma once

#include <Sk/Math/Matrix.hpp>

namespace Sk {
    struct Translation final : public Matrix3 {
        explicit Translation(float x, float y);
        explicit Translation(const Vector2& t);
        Vector2 getTranslationVector() const;
    };

    Translation operator*(const Translation& lhs, const Translation& rhs);
    Translation invert(const Translation& t);
}