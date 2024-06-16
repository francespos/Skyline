#pragma once 

#include <Sk/Math/Vector.hpp>

namespace Sk {
    template<unsigned short N> struct Matrix {
        std::array<float, N * N> v;
    
        float operator()(unsigned short r, unsigned short c) const;
        float& operator()(unsigned short r, unsigned short c);
    
        Matrix& operator+=(const Matrix& rhs);
        Matrix& operator-=(const Matrix& rhs);
    
        Matrix& operator*=(float rhs);
        Matrix& operator*=(const Matrix& rhs);
    
        Matrix& operator/=(float rhs);
    };

    using Matrix2 = Matrix<2>;
    using Matrix3 = Matrix<3>;

    template<unsigned short N>
    bool operator==(const Matrix<N>& lhs, const Matrix<N>& rhs);

    template<unsigned short N>
    bool operator!=(const Matrix<N>& lhs, const Matrix<N>& rhs); 

    template<unsigned short N>
    Matrix<N> operator+(const Matrix<N>& lhs, const Matrix<N>& rhs);

    template<unsigned short N>
    Matrix<N> operator-(const Matrix<N>& lhs, const Matrix<N>& rhs);

    template<unsigned short N>
    Matrix<N> operator*(const Matrix<N>& lhs, float rhs);

    template<unsigned short N>
    Matrix<N> operator*(float lhs, const Matrix<N>& rhs);

    template<unsigned short N>
    Matrix<N> operator*(const Matrix<N>& lhs, const Matrix<N>& rhs);

    template<unsigned short N>
    Vector<N> operator*(const Matrix<N>& lhs, const Vector<N>& rhs);

    template<unsigned short N>
    Matrix<N> operator/(const Matrix<N>& lhs, float rhs);

    float getDeterminant(const Matrix2& m);
    float getDeterminant(const Matrix3& m);

    Matrix2 invert(const Matrix2& m);
    Matrix3 invert(const Matrix3& m);

    template<unsigned short N>
    float Matrix<N>::operator()(unsigned short r, unsigned short c) const {
        return v[r * N + c];
    }

    template<unsigned short N>
    float& Matrix<N>::operator()(unsigned short r, unsigned short c) {
        return v[r * N + c];
    }

    template<unsigned short N>
    Matrix<N>& Matrix<N>::operator+=(const Matrix& rhs) {
        *this = *this + rhs;
        return *this;
    }

    template<unsigned short N>
    Matrix<N>& Matrix<N>::operator-=(const Matrix& rhs) {
        *this = *this - rhs;
        return *this;
    }

    template<unsigned short N>
    Matrix<N>& Matrix<N>::operator*=(float rhs) {
        *this = *this * rhs;
        return *this;
    }

    template<unsigned short N>
    Matrix<N>& Matrix<N>::operator*=(const Matrix<N>& rhs) {
        *this = *this * rhs;
        return *this;
    }

    template<unsigned short N>
    Matrix<N>& Matrix<N>::operator/=(float rhs) {
        *this = *this / rhs;
        return *this;
    }

    template<unsigned short N>
    bool operator==(const Matrix<N>& lhs, const Matrix<N>& rhs) {
        return lhs.v == rhs.v;
    }

    template<unsigned short N>
    bool operator!=(const Matrix<N>& lhs, const Matrix<N>& rhs) {
        return lhs.v != rhs.v;
    }

    template<unsigned short N>
    Matrix<N> operator+(const Matrix<N>& lhs, const Matrix<N>& rhs) {
        Matrix<N> ret{lhs};
        
        for (unsigned short i = 0; i < N * N; ++i) {
            ret.v[i] += rhs.v[i];
        }

        return ret;
    }

    template<unsigned short N>
    Matrix<N> operator-(const Matrix<N>& lhs, const Matrix<N>& rhs) {
        Matrix<N> ret{lhs};
        
        for (unsigned short i = 0; i < N * N; ++i) {
            ret.v[i] -= rhs.v[i];
        }

        return ret;
    }

    template<unsigned short N>
    Matrix<N> operator*(const Matrix<N>& lhs, float rhs) {
        Matrix<N> ret{lhs};
        
        for (unsigned short i = 0; i < N * N; ++i) {
            ret.v[i] *= rhs;
        }

        return ret;
    }
        
    template<unsigned short N>
    Matrix<N> operator*(float lhs, const Matrix<N>& rhs) {
        return rhs * lhs;
    }

    template<unsigned short N>
    Matrix<N> operator*(const Matrix<N>& lhs, const Matrix<N>& rhs) {
        Matrix<N> ret{};

        for (unsigned short i = 0; i < N; ++i) {
            for (unsigned short j = 0; j < N; ++j) {
                for (unsigned short k = 0; k < N; ++k) {
                    ret(i, j) += lhs(i, k) * rhs(k, j);
                }
            }
        }

        return ret;
    }

    template<unsigned short N>
    Vector<N> operator*(const Matrix<N>& lhs, const Vector<N>& rhs) {
        Vector<N> ret{};

        for (unsigned short i = 0; i < N; ++i) {
            for (unsigned short j = 0; j < N; ++j) {
                ret(i) += lhs(i, j) * rhs(j);
            }
        }

        return ret;
    }

    template<unsigned short N>
    Matrix<N> operator/(const Matrix<N>& lhs, float rhs) {
        Matrix<N> ret{lhs};
        
        for (unsigned short i = 0; i < N * N; ++i) {
            ret.v[i] /= rhs;
        }

        return ret;
    }
}