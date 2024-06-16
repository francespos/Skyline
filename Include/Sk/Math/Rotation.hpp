#pragma once

#include <Sk/Math/Matrix.hpp>

namespace Sk {
    struct Rotation final : public Matrix3 {
        explicit Rotation(float angle);
        float getAngle() const;
    };

    Rotation operator*(const Rotation& lhs, const Rotation& rhs);
    Rotation invert(const Rotation& r);
}