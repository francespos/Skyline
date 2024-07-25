#pragma once

namespace Sk {
    class Context {
    public:
        Context();
        ~Context();

        void pollEvents();
    };
}