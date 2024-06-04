#pragma once

#include <Sk/Concepts.hpp>
#include <array>
#include <cmath>

namespace Sk {
    template<Numeric T, unsigned short N> struct Vector {
        std::array<T, N> v;

        T operator()(unsigned short i) const;
        T& operator()(unsigned short i);
    
        Vector& operator+=(const Vector& rhs);
        Vector& operator-=(const Vector& rhs);
    
        Vector& operator*=(T rhs);
        Vector& operator/=(T rhs);
    };

    template<Numeric T, unsigned short N>
    bool operator==(const Vector<T, N>& lhs, const Vector<T, N>& rhs);

    template<Numeric T, unsigned short N>
    bool operator!=(const Vector<T, N>& lhs, const Vector<T, N>& rhs);

    template<Numeric T, unsigned short N>
    Vector<T, N> operator+(Vector<T, N> lhs, const Vector<T, N>& rhs);

    template<Numeric T, unsigned short N>
    Vector<T, N> operator-(Vector<T, N> lhs, const Vector<T, N>& rhs);

    template<Numeric T, unsigned short N>
    Vector<T, N> operator*(T lhs, Vector<T, N> rhs);

    template<Numeric T, unsigned short N>
    Vector<T, N> operator*(Vector<T, N> lhs, T rhs);

    template<Numeric T, unsigned short N>
    Vector<T, N> operator/(Vector<T, N> lhs, T rhs);

    template<Numeric T, unsigned short N>
    T getDotProduct(const Vector<T, N>& v1, const Vector<T, N>& v2);

    template<Numeric T>
    Vector<T, 3> getCrossProduct(const Vector<T, 3>& v1, const Vector<T, 3>& v2);

    template<Numeric T, unsigned short N>
    T getLength(const Vector<T, N>& v);

    template<Numeric T, unsigned short N>
    T getLength2(const Vector<T, N>& v);

    template<Numeric T, unsigned short N>
    Vector<T, N> normalize(const Vector<T, N>& v);

    template<Numeric T, unsigned short N>
    T Vector<T, N>::operator()(unsigned short i) const {
        return v[i];
    }

    template<Numeric T, unsigned short N>
    T& Vector<T, N>::operator()(unsigned short i) {
        return v[i];
    }

    template<Numeric T, unsigned short N>
    Vector<T, N>& Vector<T, N>::operator+=(const Vector& rhs) {
        for (unsigned short i = 0; i < N; ++i) {
            v[i] += rhs(i);
        }

        return *this;
    }

    template<Numeric T, unsigned short N>
    Vector<T, N>& Vector<T, N>::operator-=(const Vector& rhs) {
        for (unsigned short i = 0; i < N; ++i) {
            v[i] -= rhs(i);
        }

        return *this;
    }

    template<Numeric T, unsigned short N>
    Vector<T, N>& Vector<T, N>::operator*=(T rhs) {
        for (unsigned short i = 0; i < N; ++i) {
            v[i] *= rhs;
        }

        return *this;
    }

    template<Numeric T, unsigned short N>
    Vector<T, N>& Vector<T, N>::operator/=(T rhs) {
        for (unsigned short i = 0; i < N; ++i) {
            v[i] /= rhs;
        }

        return *this;
    }

    template<Numeric T, unsigned short N>
    bool operator==(const Vector<T, N>& lhs, const Vector<T, N>& rhs) {
        return lhs.v == rhs.v;
    }

    template<Numeric T, unsigned short N>
    bool operator!=(const Vector<T, N>& lhs, const Vector<T, N>& rhs) {
        return lhs.v != rhs.v;
    }

    template<Numeric T, unsigned short N>
    Vector<T, N> operator+(Vector<T, N> lhs, const Vector<T, N>& rhs) {
        lhs += rhs;
        return lhs;
    }

    template<Numeric T, unsigned short N>
    Vector<T, N> operator-(Vector<T, N> lhs, const Vector<T, N>& rhs) {
        lhs -= rhs;
        return lhs;
    }

    template<Numeric T, unsigned short N>
    Vector<T, N> operator*(T lhs, Vector<T, N> rhs) {
        rhs *= lhs;
        return rhs;
    }

    template<Numeric T, unsigned short N>
    Vector<T, N> operator*(Vector<T, N> lhs, T rhs) {
        lhs *= rhs;
        return lhs;
    }

    template<Numeric T, unsigned short N>
    Vector<T, N> operator/(Vector<T, N> lhs, T rhs) {
        lhs /= rhs;
        return lhs;
    }

    template<Numeric T, unsigned short N>
    T getDotProduct(const Vector<T, N>& v1, const Vector<T, N>& v2) {
        T ret{};
    
        for (unsigned short i = 0; i < N; ++i) {
            ret += v1(i) * v2(i);
        }
        
        return ret;
    }

    template<Numeric T>
    Vector<T, 3> getCrossProduct(const Vector<T, 3>& v1, const Vector<T, 3>& v2) {
        Vector<T, 3> ret{v1(1) * v2(2)- v1(2) * v2(1), 
            v1(0) * v2(2) - v1(2) * v2(0), 
            v1(0) * v2(1) - v1(1) * v2(0)};

        return ret;
    }

    template<Numeric T, unsigned short N>
    T getLength(const Vector<T, N>& v) {
        return std::sqrt(getLength2(v));
    }

    template<Numeric T, unsigned short N>
    T getLength2(const Vector<T, N>& v) {
        return getDotProduct(v, v);
    }

    template<Numeric T, unsigned short N>
    Vector<T, N> normalize(const Vector<T, N>& v) {
        return v / getLength(v);
    }
}
