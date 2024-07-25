#include <Sk/Context/Window.hpp>

namespace Sk {
    Window::Window(const Context& context, int width, int height, std::string_view name) {
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, name.data(), nullptr, nullptr);
    }

    Window::~Window() {
        glfwDestroyWindow(window);
    }

    GLFWwindow* Window::getGLFWwindow() {
        return window;
    }

    bool Window::shouldClose() {
        return glfwWindowShouldClose(window);
    }
}