#pragma once 

namespace Sk {
    struct Rotation;
    struct Scale;
    class Vector2;
    
    class Matrix2 {
    public:
        explicit Matrix2(float x00, float x01, float x10, float x11);
        Matrix2(const Rotation& r);
        Matrix2(const Scale& s);
    
        float operator()(unsigned short r, unsigned short c) const;
        float& operator()(unsigned short r, unsigned short c);
    
        Matrix2& operator+=(const Matrix2& rhs);
        Matrix2& operator-=(const Matrix2& rhs);
    
        Matrix2& operator*=(float rhs);
        Matrix2& operator*=(const Matrix2& rhs);
    
        Matrix2& operator/=(float rhs);
    
        Matrix2& invert();
    private:
        float v[4];
    };
    
    bool operator==(const Matrix2& lhs, const Matrix2& rhs);
    bool operator!=(const Matrix2& lhs, const Matrix2& rhs); 
    
    Matrix2 operator+(Matrix2 lhs, const Matrix2& rhs);
    Matrix2 operator-(Matrix2 lhs, const Matrix2& rhs);

    Matrix2 operator*(float lhs, Matrix2 rhs);
    Matrix2 operator*(Matrix2 lhs, float rhs);
    Matrix2 operator*(const Matrix2& lhs, const Matrix2& rhs);
    
    Vector2 operator*(const Matrix2& lhs, const Vector2& rhs);
    Matrix2 operator/(const Matrix2& lhs, float rhs);
    
    float getDeterminant(const Matrix2& m);
    Matrix2 invert(const Matrix2& m);
}
