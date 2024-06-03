#pragma once

namespace Sk {
    struct Translation {
        float x, y;
        explicit Translation(float x, float y);
        Translation& invert();
    };

    Translation invert(const Translation& t);
}
