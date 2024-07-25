#include <Sk/Context/Context.hpp>
#include <GLFW/glfw3.h>

namespace Sk {
    Context::Context() {
        glfwInit();
    }

    Context::~Context() {
        glfwTerminate();
    }

    void Context::pollEvents() {
        glfwPollEvents();
    }
}