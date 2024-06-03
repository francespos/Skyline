namespace Sk {
    class Matrix3;
    struct Translation;

    struct Rotation {
        float c, s;
        explicit Rotation(float angle);

        float getAngle() const;
        Rotation& invert();
    };

    Matrix3 operator*(const Rotation& r, const Translation& t);
    Rotation invert(const Rotation& r);
}
