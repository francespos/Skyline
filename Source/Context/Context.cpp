#include <Sk/Context/Context.hpp>
#include <GLFW/glfw3.h>

namespace Sk {
    std::weak_ptr<Context> Context::instance{};

    Context::~Context() {
        glfwTerminate();
    }

    std::shared_ptr<Context> Context::getInstance() {
        auto ret{ instance.lock() };

        if (ret == nullptr) {
            ret.reset(new Context{});
            instance = ret;
        }

        return ret;
    }

    void Context::pollEvents() {
        glfwPollEvents();
    }

    Context::Context() {
        glfwInit();
    }
}