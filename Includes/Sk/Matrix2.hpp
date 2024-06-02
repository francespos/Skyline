#pragma once 

#include <Sk/Vector2.hpp>

namespace Sk {
    class Matrix2 {
    public:
        Matrix2(float x00, float x01, float x10, float x11);
        Matrix2(const Rotation& r);
        Matrix2(const Scale& s);

        float operator()(unsigned short rowPos, unsigned short colPos) const;
        float& operator()(unsigned short rowPos, unsigned short colPos);

        Matrix2& operator+=(const Matrix2& rhs);
        Matrix2& operator-=(const Matrix2& rhs);

        Matrix2& operator*=(float rhs);
        Matrix2& operator*=(const Matrix2& rhs);

        Matrix2& operator/=(float rhs);

        Matrix2& invert();
    private:
        float values[4];
    };

    bool operator==(const Matrix2& lhs, const Matrix2& rhs);
    bool operator!=(const Matrix2& lhs, const Matrix2& rhs); 

    Matrix2 operator+(const Matrix2& lhs, const Matrix2& rhs);
    Matrix2 operator-(const Matrix2& lhs, const Matrix2& rhs);

    Matrix2 operator*(const Matrix2& lhs, float rhs);
    Matrix2 operator*(const Matrix2& lhs, const Matrix2& rhs);

    Vector2 operator*(const Matrix2& lhs, const Vector2& rhs);

    float getDeterminant(const Matrix2& m);
    Matrix2 getInverse(const Matrix2& m);
}
