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

/// @brief Computes dot product of two vectors.
float getDotProduct(const Vector2& v1, const Vector2& v2);

/// @brief Computes vector's length.
float getLength(const Vector2& v);

/// @brief Computes vector's squared length.
float getLength2(const Vector2& v);

/// @brief Normalizes a vector.
Vector2 normalize(const Vector2& v);
} // namespace Sk
