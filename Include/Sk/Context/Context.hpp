#pragma once

#include <memory>

namespace Sk {
    class Context {
    public:
        ~Context();

        static std::shared_ptr<Context> getInstance();
        void pollEvents();
    private:
        Context();

        static std::weak_ptr<Context> instance;
    };
}