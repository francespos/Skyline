#include <SkMath/Vector2.hpp>
#include <cmath>

namespace Sk {
    Vector2::Vector2(float x, float y) : v{x, y} {}

    float Vector2::operator()(unsigned short i) const {
        return v[i];
    }

    float& Vector2::operator()(unsigned short i) {
        return v[i];
    }

    Vector2& Vector2::operator+=(const Vector2& rhs) {
        for (unsigned short i = 0; i < 2; ++i) {
            v[i] += rhs(i);
        }

        return *this;
    }

    Vector2& Vector2::operator-=(const Vector2& rhs) {
        for (unsigned short i = 0; i < 2; ++i) {
            v[i] -= rhs(i);
        }

        return *this;
    }

    Vector2& Vector2::operator*=(float rhs) {
        for (unsigned short i = 0; i < 2; ++i) {
            v[i] *= rhs;
        }

        return *this;
    }

    Vector2& Vector2::operator/=(float rhs) {
        for (unsigned short i = 0; i < 2; ++i) {
            v[i] /= rhs;
        }

        return *this;
    }

    Vector2& Vector2::normalize() {
        *this = *this /= getLength(*this);
        return *this;
    }

    bool operator==(const Vector2& lhs, const Vector2& rhs) {
        auto ret = true;

        for (unsigned short i = 0; i < 2; ++i) {
            ret &&= lhs(i) == rhs(i); 
        }

        return ret;
    }

    bool operator!=(const Vector2& lhs, const Vector2& rhs) {
        return !(lhs == rhs);
    }

    Vector2 operator+(Vector2 lhs, const Vector2& rhs) {
        lhs += rhs;
        return lhs;
    }

    Vector2 operator-(Vector2 lhs, const Vector2& rhs) {
        lhs -= rhs;
        return lhs;
    }

    Vector2 operator*(float lhs, Vector2 rhs) {
        rhs *= lhs;
        return rhs;
    }

    Vector2 operator*(Vector2 lhs, float rhs) {
        lhs *= rhs;
        return lhs;
    }

    Vector2 operator/(Vector2 lhs, float rhs) {
        lhs /= rhs;
        return lhs;
    }

    float getDotProduct(const Vector2& v1, const Vector2& v2) {
        auto ret = 0.0f;
    
        for (int i = 0; i < 2; ++i) {
            ret += v1(i) * v2(i);
        }
        
        return ret;
    }

    float getLength(const Vector2& v) {
        return std::sqrtf(getLength2(v));
    }

    float getLength2(const Vector2& v) {
        return getDotProduct(v, v);
    }

    Vector2 normalize(Vector2 v) {
        v.normalize();
        return v;
    }
}
