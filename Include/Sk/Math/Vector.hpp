#pragma once

#include <array>
#include <cmath>

namespace Sk {
    template<unsigned short N> struct Vector {
        std::array<float, N> v;

        float operator()(unsigned short i) const;
        float& operator()(unsigned short i);
    
        Vector& operator+=(const Vector& rhs);
        Vector& operator-=(const Vector& rhs);
    
        Vector& operator*=(float rhs);
        Vector& operator/=(float rhs);
    };

    using Vector2 = Vector<2>;
    using Vector3 = Vector<3>;

    template<unsigned short N>
    bool operator==(const Vector<N>& lhs, const Vector<N>& rhs);

    template<unsigned short N>
    bool operator!=(const Vector<N>& lhs, const Vector<N>& rhs);

    template<unsigned short N>
    Vector<N> operator+(const Vector<N>& lhs, const Vector<N>& rhs);

    template<unsigned short N>
    Vector<N> operator-(const Vector<N>& lhs, const Vector<N>& rhs);

    template<unsigned short N>
    Vector<N> operator*(const Vector<N>& lhs, float rhs);

    template<unsigned short N>
    Vector<N> operator*(float lhs, const Vector<N>& rhs);

    template<unsigned short N>
    Vector<N> operator/(const Vector<N>& lhs, float rhs);

    template<unsigned short N>
    float getDotProduct(const Vector<N>& lhs, const Vector<N>& rhs);

    template<unsigned short N>
    float getLength(const Vector<N>& v);

    template<unsigned short N>
    float getLength2(const Vector<N>& v);

    template<unsigned short N>
    Vector<N> normalize(const Vector<N>& v);

    Vector3 getCrossProduct(const Vector3& lhs, const Vector3& rhs);

    Vector2 getVector2(const Vector3& v);
    Vector3 getVector3(const Vector2& v);

    template<unsigned short N>
    float Vector<N>::operator()(unsigned short i) const {
        return v[i];
    }

    template<unsigned short N>
    float& Vector<N>::operator()(unsigned short i) {
        return v[i];
    }

    template<unsigned short N>
    Vector<N>& Vector<N>::operator+=(const Vector& rhs) {
        *this = *this + rhs;
        return *this;
    }

    template<unsigned short N>
    Vector<N>& Vector<N>::operator-=(const Vector& rhs) {
        *this = *this - rhs;
        return *this;
    }

    template<unsigned short N>
    Vector<N>& Vector<N>::operator*=(float rhs) {
        *this = *this * rhs;
        return *this; 
    }

    template<unsigned short N>
    Vector<N>& Vector<N>::operator/=(float rhs) {
        *this = *this / rhs;
        return *this;
    }

    template<unsigned short N>
    bool operator==(const Vector<N>& lhs, const Vector<N>& rhs) {
        return lhs.v == rhs.v;
    }

    template<unsigned short N>
    bool operator!=(const Vector<N>& lhs, const Vector<N>& rhs) {
        return lhs.v != rhs.v;
    }

    template<unsigned short N>
    Vector<N> operator+(const Vector<N>& lhs, const Vector<N>& rhs) {
        Vector<N> ret{lhs};

        for (unsigned int i = 0; i < N; ++i) {
            ret(i) += rhs(i);
        }
        
        return ret;
    }

    template<unsigned short N>
    Vector<N> operator-(const Vector<N>& lhs, const Vector<N>& rhs) {
        Vector<N> ret{lhs};

        for (unsigned int i = 0; i < N; ++i) {
            ret(i) -= rhs(i);
        }
        
        return ret;
    }

    template<unsigned short N>
    Vector<N> operator*(const Vector<N>& lhs, T rhs) {
        Vector<N> ret{lhs};

        for (unsigned int i = 0; i < N; ++i) {
            ret(i) *= rhs;
        }
        
        return ret;
    }

    template<unsigned short N>
    Vector<N> operator*(float lhs, const Vector<N>& rhs) {
        return rhs * lhs;
    }

    template<Numeric T, unsigned short N>
    Vector<T, N> operator/(Vector<T, N> lhs, T rhs) {
        lhs /= rhs;
        return lhs;
    }

    template<unsigned short N>
    float getDotProduct(const Vector<N>& lhs, const Vector<N>& rhs) {
        float ret = 0.0f;
    
        for (unsigned short i = 0; i < N; ++i) {
            ret += lhs(i) * rhs(i);
        }
        
        return ret;
    }

    template<unsigned short N>
    float getLength(const Vector<N>& v) {
        return std::sqrt(getLength2(v));
    }

    template<unsigned short N>
    float getLength2(const Vector<N>& v) {
        return getDotProduct(v, v);
    }

    template<unsigned short N>
    Vector<N> normalize(const Vector<N>& v) {
        return v / getLength(v);
    }

    Vector3 getCrossProduct(const Vector3& lhs, const Vector3& rhs) {
        Vector3 ret{lhs(1) * rhs(2)- lhs(2) * rhs(1), 
            lhs(0) * rhs(2) - lhs(2) * rhs(0), 
            lhs(0) * rhs(1) - lhs(1) * rhs(0)};

        return ret;
    }

    Vector2 getVector2(const Vector3& v) {
        Vector2 ret{v(0), v(1)};
        return ret;
    }

    Vector3 getVector3(const Vector2& v) {
        Vector3 ret{v(0), v(1), 1.0f};
        return ret;
    }
}
