#pragma once

namespace Sk {
    class Translation {
    public:
        explicit Translation(float x, float y);
        Translation& invert();
    private:
        float x, y;
    }

    Translation invert(const Translation& t);
}
