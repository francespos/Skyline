namespace Sk {
    struct Scale {
        float x, y;
        explicit Scale(float x, float y);
        Scale& invert();
    };

    Scale invert(const Scale& s);
}
