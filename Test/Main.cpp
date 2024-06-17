#include <Sk/Math/Transform.hpp>
#include <Sk/Math/Float.hpp>
#include <iostream>

template <unsigned int N>
std::ostream& operator<<(std::ostream& out, const Sk::Vector<N>& v) {
    out << "[ ";

    for (unsigned short i = 0; i < N; ++i) {
        out << v(i) << " ";
    }

    out << "]";

    return out;
}

template <unsigned int N>
std::ostream& operator<<(std::ostream& out, const Sk::Matrix<N>& m) {
    for (unsigned short i = 0; i < N; ++i) {
        out << "[ ";

        for (unsigned short j = 0; j < N; ++j) {
            out << m(i, j) << " ";
        }

        out << "]\n";
    }

    return out;
}

int main() {
    Sk::Vector3 v1{1.0f, 2.0f, 3.0f};
    Sk::Vector3 v2{4.0f, 5.0f, 6.0f};

    std::cout << "v1 = " << v1 << "\n";
    std::cout << "v2 = " << v2 << "\n";

    Sk::Translation t1{1.0f, 2.0f};
    std::cout << "t1 =\n" << t1 << "\n";

    Sk::Rotation r1{Sk::getPi()};
    std::cout << "r1 =\n" << r1 << "\n";

    std::cout << "Test completed successfully.";
}