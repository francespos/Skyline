#pragma once

#include <SkMath/Concepts.hpp>

template<Numeric T> struct Rotation {
    T angle;

    explicit Rotation(T angle);
    Rotation& invert();
}

template<Numeric T>
Rotation<T> invert(const Rotation<T> r);

template<Numeric T>
Rotation<T>::Rotation(T angle) : angle{angle} {}

template<Numeric T>
Rotation<T>& Rotation<T>::invert() {
    angle = -angle;
    return *this;
}

template<Numeric T>
Rotation<T> invert(const Rotation<T> r) {
    r.invert();
    return r;
}

template
