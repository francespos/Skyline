#pragma once

#include <string_view>
#include <GLFW/glfw3.h>

namespace Sk {
    class Context;

    class Window {
    public:
        explicit Window([[maybe_unused]] const Context& context, int width, int height, std::string_view name);
        ~Window();

        GLFWwindow* getGLFWwindow();
        bool shouldClose();
    private:
        GLFWwindow* window{ nullptr };
    };
}