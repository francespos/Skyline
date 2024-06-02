#pragma once

namespace Sk {
class Vector2;

class Vector3 {
public:
    Vector3(float x, float y, float z);

    float operator()(unsigned short i) const;
    float& operator()(unsigned short i);

    Vector3& operator+=(const Vector3& rhs);
    Vector3& operator-=(const Vector3& rhs);

    Vector3& operator*=(float rhs);
    Vector3& operator/=(float rhs);

    Vector3& normalize();
private:
    float v[3];
};

float getDotProduct(const Vector3& v1, const Vector3& v2);
Vector3 getCrossProduct(const Vector3& v1, const Vector3& v2);

float getLength(const Vector3& v);
float getLength2(const Vector3& v);

Vector3 normalize(const Vector3& v);
Vector3 convertToHomogeneousCoordinates(const Vector2& v);
} // namespace Sk
