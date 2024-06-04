#pragma once

#include <type_traits>

namespace Sk {
    template<typename T>
    concept Numeric = std::is_arithmetic_v<T>;
}
