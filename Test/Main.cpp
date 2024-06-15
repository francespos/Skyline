#include <Sk/Math/Matrix.hpp>
#include <iostream>

template <unsigned int N>
std::ostream& operator<<(std::ostream& out, const Sk::Vector<N>& v) {
    out << "[";

    for (unsigned int i = 0; i < N; ++i) {
        out << v(i) << " ";
    }

    out << "]";

    return out;
}

int main() {
    Sk::Vector3 v1{1.0f, 2.0f, 3.0f};
    Sk::Vector3 v2{4.0f, 5.0f, 6.0f};

    std::cout << "v1 = " << v1 << "\n";
    std::cout << "v2 = " << v2 << "\n";

    std::cout << "Test completed successfully.";
}