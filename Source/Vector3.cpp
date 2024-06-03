#include <SkMath/Vector3.hpp>
#include <SkMath/Vector2.hpp>
#include <cmath>

namespace Sk {
    Vector3::Vector3(float x, float y, float z) : v{x, y, z} {}

    Vector3::Vector3(const Vector2& v) : v{v(0), v(1), 0.0f} {}

    float Vector3::operator()(unsigned short i) const {
        return v[i];
    }

    float& Vector3::operator()(unsigned short i) {
        return v[i];
    }

    Vector3& Vector3::operator+=(const Vector3& rhs) {
        for (unsigned short i = 0; i < 3; ++i) {
            v[i] += rhs(i);
        }

        return *this;
    }

    Vector3& Vector3::operator-=(const Vector3& rhs) {
        for (unsigned short i = 0; i < 3; ++i) {
            v[i] -= rhs(i);
        }

        return *this;
    }

    Vector3& Vector3::operator*=(float rhs) {
        for (unsigned short i = 0; i < 3; ++i) {
            v[i] *= rhs;
        }

        return *this;
    }

    Vector3& Vector3::operator/=(float rhs) {
        for (unsigned short i = 0; i < 3; ++i) {
            v[i] /= rhs;
        }

        return *this;
    }

    Vector3& Vector3::normalize() {
        *this = *this /= getLength(*this);
        return *this;
    }

    bool operator==(const Vector3& lhs, const Vector3& rhs) {
        auto ret = true;

        for (unsigned short i = 0; i < 3; ++i) {
            ret &&= lhs(i) == rhs(i); 
        }

        return ret;
    }

    bool operator!=(const Vector3& lhs, const Vector3& rhs) {
        return !(lhs == rhs);
    }

    Vector3 operator+(Vector3 lhs, const Vector3& rhs) {
        lhs += rhs;
        return lhs;
    }

    Vector3 operator-(Vector3 lhs, const Vector3& rhs) {
        lhs -= rhs;
        return lhs;
    }

    Vector3 operator*(float lhs, Vector3 rhs) {
        rhs *= lhs;
        return rhs;
    }

    Vector3 operator*(Vector3 lhs, float rhs) {
        lhs *= rhs;
        return lhs;
    }

    Vector3 operator/(Vector3 lhs, float rhs) {
        lhs /= rhs;
        return lhs;
    }

    float getDotProduct(const Vector3& v1, const Vector3& v2) {
        auto ret = 0.0f;
    
        for (int i = 0; i < 3; ++i) {
            ret += v1(i) * v2(i);
        }
        
        return ret;
    }

    Vector3 getCrossProduct(const Vector3& v1, const Vector3& v2) {
        Vec3 ret{v1(1) * v2(2)- v1(2) * v2(1), 
            v1(0) * v2(2) - v1(2) * v2(0), 
            v1(0) * v2(1) - v1(1) * v2(0)};

        return ret;
    }

    float getLength(const Vector3& v) {
        return std::sqrtf(getLength2(v));
    }

    float getLength2(const Vector3& v) {
        return getDotProduct(v, v);
    }

    Vector3 normalize(Vector3 v) {
        v.normalize();
        return v;
    }
}
