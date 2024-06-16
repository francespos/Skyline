#include <Sk/Math/Matrix.hpp>

namespace Sk {
    float getDeterminant(const Matrix2& m) {
        return m(0, 0) * m(1, 1) - m(0, 1) * m(1, 0);
    }

    float getDeterminant(const Matrix3& m) {
        return m(0, 0) * (m(1, 1) * m(2, 2) - m(1, 2) * m(2, 1)) -
            m(0, 1) * (m(1, 0) * m(2, 2) - m(1, 2) * m(2, 0)) +
            m(0, 2) * (m(1, 0) * m(2, 1) - m(1, 1) * m(2, 0));
    }

    Matrix2 invert(const Matrix2& m) {
        Matrix2 ret{m(1, 1), -m(1, 0), -m(0, 1), m(0, 0)};
        ret /= getDeterminant(m);
        return ret;
    }

    Matrix3 invert(const Matrix3& m) {
        Matrix<3> ret{m(1, 1) * m(2, 2) - m(1, 2) * m(2, 1),
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