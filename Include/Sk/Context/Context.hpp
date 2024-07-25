#pragma once

namespace Sk {
    class Context {
    public:
        explicit Context();
        ~Context();

        void pollEvents();
    };
}