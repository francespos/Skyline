#include <SkMath/Matrix3.hpp>
#include <SkMath/Translation.hpp>
#include <SkMath/Rotation.hpp>
#include <SkMath/Scale.hpp>
#include <SkMath/Matrix2.hpp>
#include <SkMath/Vector3.hpp>

namespace Sk {
    Matrix3::Matrix3(float x00, float x01, float x02, 
        float x10, float x11, float x12,
        float x20, float x21, float x22)
        : v{x00, x01, x02, x10, x11, x12, x20, x21, x22} {}

    Matrix3::Matrix3(const Translation& t) 
        : v{0.0f, 0.0f, t.x, 0.0f, 0.0f, t.y, 0.0f, 0.0f, 1.0f} {}

    Matrix3::Matrix3(const Rotation& r) 
        : v{r.c, -r.s, 0.0f, r.s, r.c, 0.0f, 0.0f, 0.0f, 1.0f} {}

    Matrix3::Matrix3(const Scale& s)  
        : v{s.x, 0.0f, 0.0f, 0.0f, s.y, 0.0f, 0.0f, 0.0f, 1.0f} {}

    Matrix3::Matrix3(const Rotation& r, const Translation& t)
        : v{r.c, -r.s, t.x, r.s, r.c, t.y, 0.0f, 0.0f, 1.0f} {}

    Matrix3::Matrix3(const Matrix2& m)
        : v{m(0, 0), m(0, 1), 0.0f, m(1, 0), m(1, 1), 0.0f, 0.0f, 0.0f, 1.0f} {}
    
    float Matrix3::operator()(unsigned short r, unsigned short c) const {
        return v[r * 3 + c];
    }

    float& Matrix3::operator()(unsigned short r, unsigned short c) const {
        return v[r * 3 + c];
    }

    Matrix3& Matrix3::operator+=(const Matrix3& rhs) {
        for (unsigned short i = 0; i < 9; ++i) {
            v[i] += rhs.v[i];
        }

        return *this;
    }

    Matrix3& Matrix3::operator-=(const Matrix3& rhs) {
        for (unsigned short i = 0; i < 9; ++i) {
            v[i] -= rhs.v[i];
        }

        return *this;
    }

    Matrix3& Matrix3::operator*=(float rhs) {
        for (unsigned short i = 0; i < 9; ++i) {
            v[i] *= rhs;
        }

        return *this;
    }

    Matrix3& Matrix3::operator*=(const Matrix3& rhs) {
        *this = *this * rhs;
        return *this;
    }

    Matrix3& Matrix3::operator/=(float rhs) {
        for (unsigned short i = 0; i < 9; ++i) {
            v[i] /= rhs;
        }

        return *this;
    }

    Matrix3& Matrix3::invert() {
        *this = invert(*this);
        return *this;
    }

    bool operator==(const Matrix3& lhs, const Matrix3& rhs) {
        auto ret = true;
    
        for (unsigned short i = 0; i < 3; ++i) {
            for (unsigned short j = 0; j < 3; ++j) {
                ret &&= lhs(i, j) == rhs(i, j); 
            }
        }

        return ret;
    }

    bool operator!=(const Matrix3& lhs, const Matrix3& rhs) {
        return !(lhs == rhs);
    }

    Matrix3 operator+(Matrix3 lhs, const Matrix3& rhs) {
        lhs += rhs;
        return lhs;
    }

    Matrix3 operator-(Matrix3 lhs, const Matrix3& rhs) {
        lhs -= rhs;
        return lhs;
    }

    Matrix3 operator*(float lhs, Matrix3 rhs) {
        rhs *= lhs;
        return rhs;
    }

    Matrix3 operator*(Matrix3 lhs, float rhs) {
        lhs *= rhs;
        return lhs;
    }

    Matrix3 operator*(const Matrix3& lhs, const Matrix3& rhs) {
        Matrix3 ret{0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};

        for (unsigned short i = 0; i < 3; ++i) {
            for (unsigned short j = 0; j < 3; ++j) {
                for (unsigned short k = 0; k < 3; ++k) {
                    ret(i, j) += lhs(i, k) * rhs(k, j);
                }
            }
        }

        return ret;
    }

    Vector3 operator*(const Matrix3& lhs, const Vector3& rhs) {
        Vector3 ret{0.0f, 0.0f, 0.0f};

        for (unsigned short i = 0; i < 3; ++i) {
            for (unsigned short j = 0; j < 3; ++j) {
                ret(i) += lhs(i, j) * rhs(j);
            }
        }

        return ret;
    }

    Matrix3 operator/(Matrix3 lhs, float rhs) {
        lhs /= rhs;
        return lhs;
    }

    float getDeterminant(const Matrix2& m) {
        return m(0, 0) * (m(1, 1) * m(2, 2) - m(1, 2) * m(2, 1)) - 
            m(0, 1) * (m(1, 0) * m(2, 2) - m(1, 2) * m(2, 0)) + 
            m(0, 2) * (m(1, 0) * m(2, 1) - m(1, 1) * m(2, 0));
    }

    Matrix3 invert(const Matrix3& m) {
        Matrix2 ret{m(1, 1) * m(2, 2) - m(1, 2) * m(2, 1),
            m(0, 2) * m(2, 1) - m(0, 1) * m(2, 2),
            m(0, 1) * m(1, 2) - m(0, 2) * m(1, 1), 
            m(1, 2) * m(2, 0) - m(1, 0) * m(2, 2),
            m(0, 0) * m(2, 2) - m(0, 2) * m(2, 0),
            m(0, 2) * m(1, 0) - m(0, 0) * m(1, 2),
            m(1, 0) * m(2, 1) - m(1, 1) * m(2, 0),
            m(0, 1) * m(2, 0) - m(0, 0) * m(2, 1), 
            m(0, 0) * m(1, 1) - m(0, 1) * m(1, 0)};
        ret /= getDeterminant(m);
        return ret;
    }
}
