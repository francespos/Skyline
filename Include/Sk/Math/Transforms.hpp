#pragma once

#include <Sk/Math/Matrix.hpp>

namespace Sk {
    template<Numeric T> struct Rotation {
        T angle;
    
        explicit Rotation(T angle);
        Rotation& invert();
    }

    template<Numeric T>
    Rotation<T> invert(Rotation<T> r);

    template<Numeric T> struct Scaling {
        T x, y;
    
        explicit Scaling(T x, T y);
        Scaling& invert();
    }

    template<Numeric T>
    Scaling<T> invert(Scaling<T> s);
    
    template<Numeric T> struct Translation {
        T x, y;

        explicit Translation(T x, T y);
        Transaltion& invert();
    }

    template<Numeric T>
    Translation<T> invert(Translation<T> t);

    template<Numeric T, unsigned int M, unsigned int N>
    Vector<T, M> apply(const Matrix<T, M, N>& m, const Vector<T, N>& v);

    template<Numeric T, unsigned int M, unsigned int N, unsigned int P>
    Matrix<T, M, P> apply(const Matrix<T, M, N>& m1, const Matrix<T, N, P>& m2);

    template<Numeric T>
    Rotation<T> apply(const Rotation<T>& r1, const Rotation<T>& r2);
    
    template<Numeric T>
    Rotation<T>::Rotation(T angle) : angle{angle} {}
    
    template<Numeric T>
    Rotation<T>& Rotation<T>::invert() {
        angle = -angle;
        return *this;
    }
    
    template<Numeric T>
    Rotation<T> invert(Rotation<T> r) {
        r.invert();
        return r;
    }

    template<Numeric T>
    Scaling<T>::Scaling(T x, T y) : x{x}, y{y} {}

    template<Numeric T>
    Scaling<T>& Scaling<T>::invert() {
        x = 1 / x;
        y = 1 / y;
        return *this;
    }

    template<Numeric T>
    Scaling<T> invert(Scaling<T> s) {
        s.invert();
        return s;
    }

    template<Numeric T>
    Translation<T>::Translation(T x, T y): x{x}, y{y} {}

    template <Numeric T>
    Translation<T>& Translation<T>::invert() {
        x = -x;
        y = -y;
        return *this;
    }
}
