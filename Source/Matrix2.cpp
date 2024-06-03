#include <SkMath/Matrix2.hpp>
#include <SkMath/Rotation.hpp>
#include <SkMath/Scale.hpp>

namespace Sk {
    Matrix2::Matrix2(float x00, float x01, float x10, float x11)
        : v{float x00, float x01, float x10, float x11} {}

    Matrix2::Matrix2(const Rotation& r) 
        : v{r.c, -r.s, r.s, r.c} {}

    Matrix2::Matrix2(const Scale& s)  
        : v{s.x, 0.0f, s.y, 0.0f} {}

    float Matrix2::operator()(unsigned short r, unsigned short c) const {
        return v[r * 2 + c];
    }

    float& Matrix2::operator()(unsigned short r, unsigned short c) const {
        return v[r * 2 + c];
    }

    Matrix2& Matrix2::operator+=(const Matrix2& rhs) {
        for (unsigned short i = 0; i < 4; ++i) {
            v[i] += rhs.v[i];
        }

        return *this;
    }

    Matrix2& Matrix2::operator-=(const Matrix2& rhs) {
        for (unsigned short i = 0; i < 4; ++i) {
            v[i] -= rhs.v[i];
        }

        return *this;
    }

    Matrix2& Matrix2::operator*=(float rhs) {
        for (unsigned short i = 0; i < 4; ++i) {
            v[i] *= rhs;
        }

        return *this;
    }

    Matrix2& Matrix2::operator*=(const Matrix2& rhs) {
        *this = *this * rhs;
        return *this;
    }

    Matrix2& Matrix2::operator/=(float rhs) {
        for (unsigned short i = 0; i < 4; ++i) {
            v[i] /= rhs;
        }

        return *this;
    }

    Matrix2& Matrix2::invert() {
        *this = invert(*this);
        return *this;
    }

    bool operator==(const Matrix2& lhs, const Matrix2& rhs) {
        auto ret = true;
    
        for (unsigned short i = 0; i < 2; ++i) {
            for (unsigned short j = 0; j < 2; ++j) {
                ret &&= lhs(i, j) == rhs(i, j); 
            }
        }

        return ret;
    }

    bool operator!=(const Matrix2& lhs, const Matrix2& rhs) {
        return !(lhs == rhs);
    }

    Matrix2 operator+(Matrix2 lhs, const Matrix2& rhs) {
        lhs += rhs;
        return lhs;
    }

    Matrix2 operator-(Matrix2 lhs, const Matrix2& rhs) {
        lhs -= rhs;
        return lhs;
    }

    Matrix2 operator*(float lhs, Matrix2 rhs) {
        rhs *= lhs;
        return rhs;
    }

    Matrix2 operator*(Matrix2 lhs, float rhs) {
        lhs *= rhs;
        return lhs;
    }

    Matrix2 operator*(const Matrix2& lhs, const Matrix2& rhs) {
        Matrix2 ret{0.0f, 0.0f, 0.0f, 0.0f};

        for (unsigned short i = 0; i < 2; ++i) {
            for (unsigned short j = 0; j < 2; ++j) {
                for (unsigned short k = 0; k < 2; ++k) {
                    ret(i, j) += lhs(i, k) * rhs(k, j);
                }
            }
        }

        return ret;
    }

    Vector2 operator*(const Matrix2& lhs, const Vector2& rhs) {
        Vector2 ret{0.0f, 0.0f};

        for (unsigned short i = 0; i < 2; ++i) {
            for (unsigned short j = 0; j < 2; ++j) {
                ret(i) += lhs(i, j) * rhs(j);
            }
        }

        return ret;
    }

    Vector2 operator/(Matrix2 lhs, float rhs) {
        lhs /= rhs;
        return lhs;
    }

    float getDeterminant(const Matrix2& m) {
        return m(0, 0) * m(1, 1) - m(0, 1) * m(1, 0);
    }

    Matrix2 invert(const Matrix2& m) {
        Matrix2 ret{m(1, 1), -m(1, 0), -m(0, 1), m(0, 0)};
        ret /= getDeterminant(m);
        return ret;
    }
}
