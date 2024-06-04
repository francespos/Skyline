#pragma once 

#include <SkMath/Vector.hpp>

namespace Sk {
    template<Numeric T, unsigned short M, unsigned short N> struct Matrix {
        std::array<T, M * N> v;
    
        T operator()(unsigned short r, unsigned short c) const;
        T& operator()(unsigned short r, unsigned short c);
    
        Matrix& operator+=(const Matrix& rhs);
        Matrix& operator-=(const Matrix& rhs);
    
        Matrix& operator*=(T rhs);

        template<unsigned short P>
        Matrix<T, M, P>& operator*=(const Matrix<T, N, P>& rhs);
    
        Matrix& operator/=(T rhs);
    };

    template<Numeric T, unsigned short M, unsigned short N>
    bool operator==(const Matrix<T, M, N>& lhs, const Matrix<T, M, N>& rhs);

    template<Numeric T, unsigned short M, unsigned short N>
    bool operator!=(const Matrix<T, M, N>& lhs, const Matrix<T, M, N>& rhs); 

    template<Numeric T, unsigned short M, unsigned short N>
    Matrix<T, M, N> operator+(Matrix<T, M, N> lhs, const Matrix<T, M, N>& rhs);

    template<Numeric T, unsigned short M, unsigned short N>
    Matrix<T, M, N> operator-(Matrix<T, M, N> lhs, const Matrix<T, M, N>& rhs);

    template<Numeric T, unsigned short M, unsigned short N>
    Matrix<T, M, N> operator*(T lhs, Matrix<T, M, N> rhs);

    template<Numeric T, unsigned short M, unsigned short N>
    Matrix<T, M, N> operator*(Matrix<T, M, N> lhs, T rhs);

    template<Numeric T, unsigned short M, unsigned short N, unsigned short P>
    Matrix<T, M, P> operator*(const Matrix<T, M, N>& lhs, const Matrix<T, N, P>& rhs);

    template<Numeric T, unsigned short M, unsigned short N>
    Vector<T, M> operator*(const Matrix<T, M, N>& lhs, const Vector<T, N>& rhs);

    template<Numeric T, unsigned short M, unsigned short N>
    Matrix<T, M, N> operator/(const Matrix<T, M, N>& lhs, T rhs);

    template<Numeric T>
    T getDeterminant(const Matrix<T, 2, 2>& m);

    template<Numeric T>
    T getDeterminant(const Matrix<T, 3, 3>& m);

    template<Numeric T>
    Matrix<T, 2, 2> invert(const Matrix<T, 2, 2>& m);

    template<Numeric T>
    Matrix<T, 3, 3> invert(const Matrix<T, 3, 3>& m);

    template<Numeric T, unsigned short M, unsigned short N>
    T Matrix<T, M, N>::operator()(unsigned short r, unsigned short c) const {
        return v[r * N + c];
    }

    template<Numeric T, unsigned short M, unsigned short N>
    T& Matrix<T, M, N>::operator()(unsigned short r, unsigned short c) {
        return v[r * N + c];
    }

    template<Numeric T, unsigned short M, unsigned short N>
    Matrix& Matrix<T, M, N>::operator+=(const Matrix& rhs) {
        for (unsigned short i = 0; i < M * N; ++i) {
            v[i] += rhs.v[i];
        }

        return *this;
    }

    template<Numeric T, unsigned short M, unsigned short N>
    Matrix& Matrix<T, M, N>::operator-=(const Matrix& rhs) {
        for (unsigned short i = 0; i < M * N; ++i) {
            v[i] -= rhs.v[i];
        }

        return *this;
    }

    template<Numeric T, unsigned short M, unsigned short N>
    Matrix& Matrix<T, M, N>::operator*=(T rhs) {
        for (unsigned short i = 0; i < M * N; ++i) {
            v[i] *= rhs;
        }

        return *this;
    }

    template<Numeric T, unsigned short M, unsigned short N>
    template<unsigned short P>
    Matrix<T, M, P>& Matrix<T, M, N>::operator*=(const Matrix<T, N, P>& rhs) {
        *this = *this * rhs;
        return *this;
    }

    template<Numeric T, unsigned short M, unsigned short N>
    Matrix& Matrix<T, M, N>::operator/=(T rhs) {
        for (unsigned short i = 0; i < M * N; ++i) {
            v[i] /= rhs;
        }

        return *this;
    }

    template<Numeric T, unsigned short M, unsigned short N>
    bool operator==(const Matrix<T, M, N>& lhs, const Matrix<T, M, N>& rhs) {
        return lhs.v == rhs.v;
    }

    template<Numeric T, unsigned short M, unsigned short N>
    bool operator!=(const Matrix<T, M, N>& lhs, const Matrix<T, M, N>& rhs) {
        return lhs.v != rhs.v;
    }

    template<Numeric T, unsigned short M, unsigned short N>
    Matrix<T, M, N> operator+(Matrix<T, M, N> lhs, const Matrix<T, M, N>& rhs) {
        lhs += rhs;
        return lhs;
    }

    template<Numeric T, unsigned short M, unsigned short N>
    Matrix<T, M, N> operator-(Matrix<T, M, N> lhs, const Matrix<T, M, N>& rhs) {
        lhs -= rhs;
        return lhs;
    }

    template<Numeric T, unsigned short M, unsigned short N>
    Matrix<T, M, N> operator*(T lhs, Matrix<T, M, N> rhs) {
        rhs *= lhs;
        return rhs;
    }

    template<Numeric T, unsigned short M, unsigned short N>
    Matrix<T, M, N> operator*(Matrix<T, M, N> lhs, T rhs) {
        lhs *= rhs;
        return lhs;
    ]

    template<Numeric T, unsigned short M, unsigned short N, unsigned short P>
    Matrix<T, M, P> operator*(const Matrix<T, M, N>& lhs, const Matrix<T, N, P>& rhs) {
        Matrix<T, M, P> ret{};

        for (unsigned short i = 0; i < M; ++i) {
            for (unsigned short j = 0; j < P; ++j) {
                for (unsigned short k = 0; k < N; ++k) {
                    ret(i, j) += lhs(i, k) * rhs(k, j);
                }
            }
        }

        return ret;

    }

    template<Numeric T, unsigned short M, unsigned short N>
    Vector<T, M> operator*(const Matrix<T, M, N>& lhs, const Vector<T, N>& rhs) {
        Vector<T, M> ret{};

        for (unsigned short i = 0; i < M; ++i) {
            for (unsigned short j = 0; j < N; ++j) {
                ret(i) += lhs(i, j) * rhs(j);
            }
        }

        return ret;
    }

    template<Numeric T, unsigned short M, unsigned short N>
    Matrix<T, M, N> operator/(const Matrix<T, M, N>& lhs, T rhs) {
        lhs /= rhs;
        return lhs;
    }

    template<Numeric T>
    T getDeterminant(const Matrix<T, 2, 2>& m) {
        return m(0, 0) * m(1, 1) - m(0, 1) * m(1, 0);
    }

    template<Numeric T>
    T getDeterminant(const Matrix<T, 3, 3>& m) {
        return m(0, 0) * (m(1, 1) * m(2, 2) - m(1, 2) * m(2, 1)) - 
            m(0, 1) * (m(1, 0) * m(2, 2) - m(1, 2) * m(2, 0)) + 
            m(0, 2) * (m(1, 0) * m(2, 1) - m(1, 1) * m(2, 0));
    }

    template<Numeric T>
    Matrix<T, 2, 2> invert(const Matrix<T, 2, 2>& m) {
        Matrix<T, 2, 2> ret{m(1, 1), -m(1, 0), -m(0, 1), m(0, 0)};
        ret /= getDeterminant(m);
        return ret;
    }

    template<Numeric T>
    Matrix<T, 3, 3> invert(const Matrix<T, 3, 3>& m) {
        Matrix<T, 3, 3> ret{m(1, 1) * m(2, 2) - m(1, 2) * m(2, 1),
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
