#include <Sk/Math/Rotation.hpp>

namespace Sk {
    Rotation::Rotation(float angle) 
        : Matrix3{std::cos(angle), -std::sin(angle), 0.0f
        , std::sin(angle), std::cos(angle), 0.0f
        , 0.0f, 0.0f, 1.0f} {}

    float Rotation::getAngle() const {
        return std::atan2(v[3], v[4]);
    }

    Rotation operator*(const Rotation& lhs, const Rotation& rhs) {
        Rotation ret{lhs.getAngle() + rhs.getAngle()};
        return ret;
    }

    Rotation invert(const Rotation& r) {
        Rotation ret{r};

        ret(0, 1) = -ret(0, 1);
        ret(1, 0) = -ret(1, 0);

        return ret;
    }
}