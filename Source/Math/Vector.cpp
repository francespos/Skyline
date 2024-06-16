#include <Sk/Math/Vector.hpp>

namespace Sk {
    Vector3 getCrossProduct(const Vector3& lhs, const Vector3& rhs) {
        Vector3 ret{lhs(1) * rhs(2) - lhs(2) * rhs(1),
            lhs(0) * rhs(2) - lhs(2) * rhs(0),
            lhs(0) * rhs(1) - lhs(1) * rhs(0)};

        return ret;
    }

    Vector2 getVector2(const Vector3& v) {
        Vector2 ret{v(0), v(1)};
        return ret;
    }

    Vector3 getVector3(const Vector2& v) {
        Vector3 ret{v(0), v(1), 1.0f};
        return ret;
    }
}