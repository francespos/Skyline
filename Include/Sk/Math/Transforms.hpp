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

    template<Numeric T>
    Matrix<T, 3, 3> getRotationMatrix(const Rotation& r);

    template<Numeric T>
    Matrix<T, 3, 3> getScalingMatrix(const Scaling& s);

    template<Numerix T>
    Matrix<T, 3, 3> getTranslationMatrix(const Translation& t);

    template<Numeric T>
    Matrix<T, 3, 3> apply(const Matrix<T, 3, 3>& m1, const Matrix<T, 3, 3>& m2);

    template<Numeric T>
    Vector<T, 3, 3> apply(const Matrix<T, 3, 3>& m, const Vector<T, 3, 3>& v);

    template<Numeric T>
    Rotation<T> apply(const Rotation<T>& r1, const Rotation<T>& r2);

    template<Numeric T>
    Vector<T, 3> apply(const Rotation<T>& r, const Vector<T, 3>& v);

    template<Numeric T>
    Scaling<T> apply(const Scaling<T>& s1, const Scaling<T>& s2);

    template<Numeric T>
    Vector<T, 3> apply(const Scaling<T>& s, Vector<T, 3> v);

    template<Numeric T>
    Translation<T> apply(const Translation<T>& t1, const Translation<T>& t2);

    template<Numeric T>
    Vector<T, 3> apply(const Translation<T>& t, Vector<T, 3> v);

    template<Numeric T>
    Vector<T, 3> apply(const Rotation<T>& r, const Translation<T>& t, const Vector<T, 3>);
    
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

    template<Numeric T>
    Matrix<T, 3, 3> getRotationMatrix(const Rotation& r) {
        T c = std::cos(r.angle);
        T s = std::sin(r.angle);

        Matrix<T, 3, 3> ret = {c, -s, 0,
            s, c, 0,
            0, 0, 1};

        return ret;
    }

    template<Numeric T>
    Matrix<T, 3, 3> getScalingMatrix(const Scaling& s) {
         Matrix<T, 3, 3> ret = {s.x, 0, 0,
            0, s.y, 0,
            0, 0, 1};

        return ret;       
    }

    template<Numerix T>
    Matrix<T, 3, 3> getTranslationMatrix(const Translation& t) {
         Matrix<T, 3, 3> ret = {0, 0, t.x,
            0, 0, t.y,
            0, 0, 1};

        return ret;       
    }

    template<Numeric T>
    Matrix<T, 3, 3> apply(const Matrix<T, 3, 3>& m1, const Matrix<T, 3, 3>& m2) {
        return m1 * m2;
    }

    template<Numeric T>
    Vector<T, 3, 3> apply(const Matrix<T, 3, 3>& m, const Vector<T, 3, 3>& v) {
        return m * v;
    }

    template<Numeric T>
    Rotation<T> apply(const Rotation<T>& r1, const Rotation<T>& r2) {
        Rotation<T> ret{r1.angle + r2.angle};
        return ret;
    }

    template<Numeric T>
    Vector<T, 3> apply(const Rotation<T>& r, const Vector<T, 3>& v) {
        T c = std::cos(r.angle);
        T s = std::sin(r.angle);

        Vector<T, 3> ret{c * v[0] - s * v[1], s * v[0] + c * v[1], 1};
        return ret;
    }

    template<Numeric T>
    Scaling<T> apply(const Scaling<T>& s1, const Scaling<T>& s2) {
        Scaling<T> ret{s1.x * s2.x, s1.y * s2.y};
        return ret;
    }

    template<Numeric T>
    Vector<T, 3> apply(const Scaling<T>& s, Vector<T, 3> v) {
        v[0] *= s.x;
        v[1] *= s.y;

        return v;
    }

    template<Numeric T>
    Translation<T> apply(const Translation<T>& t1, const Translation<T>& t2) {
        Translation<T> ret{t1.x + t2.x, t1.y + t2.y};
        return ret;
    }

    template<Numeric T>
    Vector<T, 3> apply(const Translation<T>& t, Vector<T, 3> v) {
            v[0] += t.x;
            v[1] += t.y;
            return v;
    }

    template<Numeric T>
    Matrix<T, 3, 3> apply(const Translation<T>& t, const Rotation<T>& r) {
        T c = std::cos(r.angle);
        T s = std::sin(r.angle);

        Matrix<T, 3, 3> ret = {c, -s, t.x,
            s, c, t.y,
            0, 0, 1};

        return ret;
    }
}
