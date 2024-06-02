#pragma once 

namespace Sk {
    class Translation;
    class Rotation;
    class Scale;
    class Vector3;
    
    class Matrix3 {
    public:
        Matrix3(float x00, float x01, float x02, 
            float x10, float x11, float x12,
            float x20, float x21, float x22);
        
        Matrix3(const Translation& t);
        Matrix3(const Rotation& r);
        Matrix3(const Scale& s);

        Matrix3(const Rotation& r, const Translation& t);
    
        float operator()(unsigned short r, unsigned short c) const;
        float& operator()(unsigned short r, unsigned short c);
    
        Matrix3& operator+=(const Matrix3& rhs);
        Matrix3& operator-=(const Matrix3& rhs);
    
        Matrix3& operator*=(float rhs);
        Matrix3& operator*=(const Matrix3& rhs);
    
        Matrix3& operator/=(float rhs);
    
        Matrix3& invert();
    private:
        float v[9];
    };
    
    bool operator==(const Matrix3& lhs, const Matrix3& rhs);
    bool operator!=(const Matrix3& lhs, const Matrix3& rhs); 
    
    Matrix2 operator+(const Matrix3& lhs, const Matrix3& rhs);
    Matrix2 operator-(const Matrix3& lhs, const Matrix3& rhs);
    
    Matrix2 operator*(const Matrix3& lhs, float rhs);
    Matrix2 operator*(const Matrix3& lhs, const Matrix3& rhs);
    
    Vector2 operator*(const Matrix3& lhs, const Vector3& rhs);
    
    float getDeterminant(const Matrix3& m);
    Matrix3 invert(const Matrix3& m);
}