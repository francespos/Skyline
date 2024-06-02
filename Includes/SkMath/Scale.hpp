namespace Sk {
    class Scale {
    public:
        explicit Scale(float x, float y);
        Scale& invert();
    private:    
        float x, y;
    };

    Scale invert(const Scale& s);
}
