#include <Sk/Math/Vector2.hpp>
#include <cmath>

namespace Sk {
    Vector2::Vector2(float x, float y) : values{ x, y } {}

    float Vector2::operator[](std::size_t pos) const {
        return values[pos];
    }

    float& Vector2::operator[](std::size_t pos) {
        return values[pos];
    }

    bool Vector2::operator==(const Vector2& rhs) const {
        return values == rhs.values;
    }

    bool Vector2::operator!=(const Vector2& rhs) const {
        return values != rhs.values;
    }

    Vector2& Vector2::operator+=(const Vector2& rhs) {
        *this = *this + rhs;
        return *this;
    }

    Vector2& Vector2::operator-=(const Vector2& rhs) {
        *this = *this - rhs;
        return *this;
    }

    Vector2& Vector2::operator*=(float rhs) {
        *this = *this * rhs;
        return *this;
    }

    Vector2& Vector2::operator/=(float rhs) {
        *this = *this / rhs;
        return *this;
    }

    Vector2 Vector2::operator+(const Vector2& rhs) const {
        return Vector2{ values[0] + rhs.values[0],
            values[1] + rhs.values[1] };
    }

    Vector2 Vector2::operator-(const Vector2& rhs) const {
        return Vector2{ values[0] - rhs.values[0],
            values[1] - rhs.values[1] };
    }

    Vector2 Vector2::operator*(float rhs) const {
        return Vector2{ values[0] * rhs, values[1] * rhs };
    }

    Vector2 Vector2::operator/(float rhs) const {
        return Vector2{ values[0] / rhs, values[1] / rhs };
    }

    Vector2& Vector2::normalize() {
        *this /= getLength();
        return *this;
    }

    Vector2& Vector2::translate(float tx, float ty) {
        *this = getTranslated(tx, ty);
        return *this;
    }

    Vector2& Vector2::translate(const Vector2& t) {
        return translate(t[0], t[1]);
    }

    Vector2& Vector2::rotate(float angle) {
        *this = getRotated(angle);
        return *this;
    }

    Vector2& Vector2::scale(float sx, float sy) {
        *this = getScaled(sx, sy);
        return *this;
    }

    Vector2& Vector2::scale(const Vector2& s) {
        return scale(s[0], s[1]);
    }

    float Vector2::getLength() const {
        return std::sqrt(getLength2());
    }

    float Vector2::getLength2() const {
        return getDotProduct(*this);
    }

    float Vector2::getDistance(const Vector2& rhs) const {
        const Vector2 difference{ *this - rhs };
        return difference.getLength();
    }

    float Vector2::getDotProduct(const Vector2& rhs) const {
        return values[0] * rhs.values[0] + 
            values[1] * rhs.values[1];
    }

    Vector2 Vector2::getNormalized() const {
        return *this / getLength();
    }

    Vector2 Vector2::getTranslated(float tx, float ty) const {
        return Vector2{ values[0] + tx, values[1] + ty };
    }

    Vector2 Vector2::getTranslated(const Vector2& t) const {
        return getTranslated(t[0], t[1]);
    }

    Vector2 Vector2::getRotated(float angle) const {
        const auto x{ values[0] };
        const auto y{ values[1] };

        const auto c{ std::cos(angle) };
        const auto s{ std::sin(angle) };

        return Vector2{ x * c + y * s, -x * s + y * c };
    }

    Vector2 Vector2::getScaled(float sx, float sy) const {
        return Vector2{ values[0] * sx, values[1] * sy };
    }

    Vector2 Vector2::getScaled(const Vector2& s) const {
        return Vector2{ s[0], s[1] };
    }

    Vector2 operator*(float lhs, const Vector2& rhs) {
        return rhs * lhs;
    }
}