#pragma once

namespace Sk {
    struct Vector2 {
        union {
            struct { 
                float x, y; 
            };

            float data[2];
        };
    };
} 
