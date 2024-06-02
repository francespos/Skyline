#pragma once

namespace Sk {
    class Translation {
    public:
        Translation(float x, float y);
        Translation invert();
    private:
        float x, y;
    }

    Translation invert(const Translation& t);
}
