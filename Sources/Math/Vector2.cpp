#include <Sk/Math/Vector2.hpp>
#include <cmath>

namespace Sk {
    bool Vector2::operator==(const Vector2& rhs) {
        return x == rhs.x && y == rhs.y;
    }

    bool Vector2::operator!=(const Vector2& rhs) {
        return x != rhs.x || y != rhs.y;
    }

    Vector2& Vector2::operator+=(const Vector2& rhs) {
        x += rhs.x;
        y += rhs.y;

        return *this;
    }

    Vector2& Vector2::operator-=(const Vector2& rhs) {
        x -= rhs.x;
        y -= rhs.y;

        return *this;
    }

    Vector2& Vector2::operator*=(float rhs) {
        x *= rhs;
        y *= rhs;

        return *this;
    }

    Vector2& Vector2::operator/=(float rhs) {
        x /= rhs;
        y /= rhs;

        return *this;
    }

    Vector2 Vector2::operator+(const Vector2& rhs) const {
        return Vector2{ x + rhs.x, y + rhs.y };
    }

    Vector2 Vector2::operator-(const Vector2& rhs) const {
        return Vector2{ x - rhs.x, y - rhs.y };
    }

    Vector2 Vector2::operator*(float rhs) const {
        return Vector2{ x * rhs, y * rhs };
    }

    Vector2 Vector2::operator/(float rhs) const {
        return Vector2{ x / rhs, y / rhs };
    }

    Vector2& Vector2::normalize() {
        *this /= getLength();
        return *this;
    }

    Vector2& Vector2::translate(float tx, float ty) {
        x += tx;
        y += ty;

        return *this;
    }

    Vector2& Vector2::rotate(float angle) {
        const auto c{ std::cos(angle) };
        const auto s{ std::sin(angle) };

        const auto ox{ x };
        const auto oy{ y };

        x = ox * c + oy * s;
        y = -ox * s + oy * c;

        return *this;
    }

    Vector2& Vector2::scale(float sx, float sy) {
        x *= sx;
        y *= sy;

        return *this;
    }

    float Vector2::getLength() const {
        return std::sqrt(getLength2());
    }

    float Vector2::getLength2() const {
        return x * x + y * y;
    }

    float Vector2::getDistance(const Vector2& rhs) const {
        return std::sqrt((x - rhs.x) * (x - rhs.x)
            + (y - rhs.y) * (y - rhs.y));
    }

    float Vector2::getDotProduct(const Vector2& rhs) const {
        return x * rhs.x + y * rhs.y;
    }

    Vector2 Vector2::getNormalized() const {
        return *this / getLength();
    }

    Vector2 Vector2::getTranslated(float tx, float ty) const {
        return Vector2{ x + tx, y + ty };
    }

    Vector2 Vector2::getRotated(float angle) const {
        const auto c = std::cos(angle);
        const auto s = std::sin(angle);

        return Vector2{ x * c + y * s, -x * s + y * c };
    }

    Vector2 Vector2::getScaled(float sx, float sy) const {
        return Vector2{ x * sx, y * sy };
    }
}