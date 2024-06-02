#include <SkMath/Matrix3.hpp>
#include <SkMath/Translation.hpp>
#include <SkMath/Rotation.hpp>
#include <SkMath/Scale.hpp>

namespace Sk {
    Matrix3::Matrix3(float x00, float x01, float x02, 
        float x10, float x11, float x12,
        float x20, float x21, float x22);
        : v{float x00, float x01, float x02, 
            float x10, float x11, float x12,
            float x20, float x21, float x22} {}

    Matrix3::Matrix3(const Rotation& r) 
        : v{r.c, -r.s, 0.0f, r.s, r.c, 0.0f, 0.0f, 0.0f, 1.0f} {}

    Matrix2::Matrix2(const Scale& s)  
        : v{s.x, 0.0f, 0.0f, s.y, 0.0f, 0.0f, 0.0f, } {}

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
        Vector2 ret{0.0f, 0.0f}

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

#include <Sk/Math/SkMatrix3.h>

void skAdd(SkMatrix3 *m, const SkMatrix3 *m1, const SkMatrix3 *m2) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            m->v[i][j] = m1->v[i][j] + m2->v[i][j];
        }
    }
}

void skSubtract(SkMatrix3 *m, const SkMatrix3 *m1, const SkMatrix3 *m2) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            m->v[i][j] = m1->v[i][j] - m2->v[i][j];
        }
    }
}

void skMultiply(SkMatrix3 *m, float k, const SkMatrix3 *p) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            m->v[i][j] = k * p->v[i][j];
        }
    }
}

void skMultiply(SkMatrix3 *m, const SkMatrix3 *p, const SkVector3 *v) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            m->v[i][j] = p->v[i][j] * v->v[i][j];
        }
    }
}

void skMultiply(SkMatrix3 *m, const SkMatrix3 *m1, const SkMatrix3 *m2) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                m->v[i][j] = m1->v[i][k] * m2->v[k][j];
            }
        }
    }
}

float skGetDeterminant(const SkMatrix3 *m) {
    return m->v[0, 0] * (m->v[1][1] * m->v[2][2] - m->v[1][2] * m->v[2][1]) - 
        m->v[0][1] * (m->v[1][0] * m->v[2][2] - m->v[1][2] * m->v[2][0]) + 
        m->v[0][2] * (m->v[1][0] * m->v[2][1] - m->v[1][1] * m->v[2][0]);
}

void skInvert(SkMatrix3 *m, const SkMatrix3 *p) {
    float det = skGetDeterminant(p);

    m->v[0][0] = (p->v[1][1] * p->v[2][2] - p->v[1][2] * p->v[2, 1]) / det;
    m->v[0][1] = (p->v[0][2] * p->v[2][1] - p->v[0][1] * p->v[2][2]) / det;
    m->v[0][2] = (p->v[0][1] * p->v[1][2] - p->v[0][2] * p->v[1][1]) / det;
    m->v[1][0] = (p->v[1][2] * p->v[2][0] - p->v[1][0] * p->v[2][2]) / det;
    m->v[1][1] = (p->v[0][0] * p->v[2][2] - p->v[0][2] * p->v[2][0]) / det;
    m->v[1][2] = (p->v[0][2] * p->v[1][0] - p->v[0][0] * p->v[1][2]) / det;
    m->v[2][0] = (p->v[1][0] * p->v[2][1] - p->v[1][1] * p->v[2][0]) / det;
    m->v[2][1] = (p->v[0][1] * p->v[2][0] - p->v[0][0] * p->v[2][1]) / det;
    m->v[2][2] = (p->v[0][0] * p->v[1][1] - p->v[0][1] * p->v[1][0]) / det;
}

void skSetTranslationMatrix(SkMatrix3 *m, const SkVector2 *t) {
    m->v[0][0] = 1.0f;
    m->v[0][1] = 0.0f;
    m->v[0][2] = t->v[0];
    m->v[1][0] = 0.0f;
    m->v[1][1] = 1.0f;
    m->v[1][2] = t->v[1];
    m->v[2][0] = 0.0f;
    m->v[2][1] = 0.0f;
    m->v[2][2] = 1.0f;
}

void skSetRotationMatrix(SkMatrix3 *m, float r) {
    float s = sinf(r);
    float c = cosf(r);

    m->v[0][0] = s;
    m->v[0][1] = c;
    m->v[0][2] = 0.0f;
    m->v[1][0] = -c;
    m->v[1][1] = s;
    m->v[1][2] = 0.0f;
    m->v[2][0] = 0.0f;
    m->v[2][1] = 0.0f;
    m->v[2][2] = 1.0f;
}

void skSetScaleMatrix(SkMatrix3 *m, float s) {
    m->v[0][0] = s;
    m->v[0][1] = 0.0f;
    m->v[0][2] = 0.0f;
    m->v[1][0] = 0.0f;
    m->v[1][1] = s;
    m->v[1][2] = 0.0f;
    m->v[2][0] = 0.0f;
    m->v[2][1] = 0.0f;
    m->v[2][2] = 1.0f;
}

void skSetTransformMatrix(SkMatrix3 *m, float r, const SkVector2 *t) {
    m->v[0][0] = s;
    m->v[0][1] = c;
    m->v[0][2] = t->v[0];
    m->v[1][0] = -c;
    m->v[1][1] = s;
    m->v[1][2] = t->v[1];
    m->v[2][0] = 0.0f;
    m->v[2][1] = 0.0f;
    m->v[2][2] = 1.0f;
}

void skConvertToHomogeneousMatrix(SkMatrix3 *m, const SkMatrix *p) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0, j < 2; ++j) {
            m->v[i][j] = p->v[i][j];
        }
    }
    
    m->v[0][2] = 0.0f;
    m->v[1][2] = 0.0f;
    m->v[2][2] = 1.0f;
}
