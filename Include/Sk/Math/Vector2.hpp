#pragma once

namespace Sk {
    struct Vector2 {
        float x, y;

        explicit Vector2() = default;
        explicit Vector2(float x, float y);

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
        Vector2& translate(const Vector2& t);

        Vector2& rotate(float angle);

        Vector2& scale(float sx, float sy);
        Vector2& scale(const Vector2& s);

        float getLength() const;
        float getLength2() const;

        float getDistance(const Vector2& rhs) const;
        float getDotProduct(const Vector2& rhs) const;

        Vector2 getNormalized() const;

        Vector2 getTranslated(float tx, float ty) const;
        Vector2 getTranslated(const Vector2& t) const;

        Vector2 getRotated(float angle) const;

        Vector2 getScaled(float sx, float sy) const;
        Vector2 getScaled(const Vector2& s) const;
    };

    Vector2 operator*(float lhs, const Vector2& rhs);
}