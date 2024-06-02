namespace Sk {
    class Matrix3;
    class Translation;

    class Rotation {
    public:
        explicit Rotation(float angle);
        Rotation& invert();
    private:
        float c, s;
    };

    Matrix3 operator*(const Rotation& r, const Translation& t);
    Rotation invert(const Rotation& r);
}
