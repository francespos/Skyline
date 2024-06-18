#include <Sk/Math/Vector.hpp>

namespace Sk {
    Vector3 getCrossProduct(const Vector3& lhs, const Vector3& rhs) {
        return Vector3{lhs(1) * rhs(2) - lhs(2) * rhs(1),
            lhs(0) * rhs(2) - lhs(2) * rhs(0),
            lhs(0) * rhs(1) - lhs(1) * rhs(0)};
    }

    Vector2 getVector2(const Vector3& v) {
        return Vector2{v(0), v(1)};
    }

    Vector3 getVector3(const Vector2& v) {
        return Vector3{v(0), v(1), 1.0f};
    }
}