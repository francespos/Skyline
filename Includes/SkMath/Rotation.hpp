namespace Sk {
    class Matrix3;
    class Translation;

    struct Rotation {
        float c, s;
        explicit Rotation(float angle);
        Rotation& invert();
    };

    Matrix3 operator*(const Rotation& r, const Translation& t);
    Rotation invert(const Rotation& r);
}
