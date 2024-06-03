#include <SkMath/Rotation.hpp>
#include <cmath>
#include <SkMath/Matrix3.hpp>
#include <SkMath/Translation.hpp>

namespace Sk {
    Rotation::Rotation(float angle) : s{sinf(angle)}, c{cosf(angle)} {}

    float Rotation::getAngle() const { return atanf(s / c); }

    Rotation& Rotation::invert() {
        *this = invert(*this);
        return *this;
    }

    Matrix3 operator*(const Rotation& r, const Translation& t) {
        Matrix3 ret{r, t};
        return ret;
    }
}
