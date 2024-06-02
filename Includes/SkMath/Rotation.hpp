namespace Sk {
    class Rotation {
    public:
        explicit Rotation(float angle);
        Rotation& invert();
    private:
        float c, s;
    };

    Rotation invert(const Rotation& r);
}
