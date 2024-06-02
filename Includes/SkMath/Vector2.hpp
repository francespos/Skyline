#pragma once

namespace Sk {
    class Vector2 {
    public:
        Vector2(float x, float y);
    
        float operator()(unsigned short i) const;
        float& operator()(unsigned short i);
    
        Vector2& operator+=(const Vector2& rhs);
        Vector2& operator-=(const Vector2& rhs);
    
        Vector2& operator*=(float rhs);
        Vector2& operator/=(float rhs);
    
        Vector2& normalize();
    private:
        float v[2];
    };

    bool operator==(const Vector2& lhs, const Vector2& rhs);
    bool operator!=(const Vector2& lhs, const Vector2& rhs);

    Vector2 operator+(const Vector2& lhs, const Vector2& rhs);
    Vector2 operator-(const Vector2& lhs, const Vector2& rhs);

    Vector2 operator*(float lhs, const Vector2& rhs);
    Vector2 operator*(const Vector2& lhs, float rhs);

    Vector2 operator/(const Vector2& lhs, float rhs);
    
    float getDotProduct(const Vector2& v1, const Vector2& v2);
    
    float getLength(const Vector2& v);
    float getLength2(const Vector2& v);
    
    Vector2 normalize(const Vector2& v);
}
