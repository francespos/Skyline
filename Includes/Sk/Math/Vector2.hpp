#pragma once

namespace Sk {
    struct Vector2 {
        float x, y;

        float operator[](unsigned short pos) const;
        float& operator[](unsigned short pos);

        bool operator==(const Vector2& rhs) const;
        bool operator!=(const Vector2& lhs) const;

        Vector2& operator+=(const Vector2& rhs);
        Vector2& operator-=(const Vector2& rhs);

        Vector2& operator*=(float rhs);
        Vector2& operator/=(float rhs);

        Vector2 operator+(const Vector2& rhs) const;
        Vector2 operator-(const Vector2& rhs) const;

        Vector2 operator*(float rhs) const;
        Vector2 operator/(float rhs) const;

        Vector2& normalize();

        Vector2& translate(float tx, float ty);
        Vector2& rotate(float angle);
        Vector2& scale(float sx, float sy);

        float getLength() const;
        float getLength2() const;

        float getDistance(const Vector2& rhs) const;
        float getDotProduct(const Vector2& rhs) const;

        Vector2 getNormalized() const;

        Vector2 getTranslated(float tx, float ty) const;
        Vector2 getRotated(float angle) const;
        Vector2 getScaled(float sx, float sy) const;
    };

    Vector2 operator*(float lhs, const Vector2& rhs);
}