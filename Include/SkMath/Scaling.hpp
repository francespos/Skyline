#pragma once

#include <SkMath/Concepts.hpp>

template<Numeric T> struct Scaling {
    T x, y;

    explicit Scaling(T x, T y);
    Scaling& invert();
}

template<Numeric T>


Scaling
