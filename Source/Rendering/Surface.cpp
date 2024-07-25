#include <Sk/Rendering/Surface.hpp>
#include <Sk/Context/Window.hpp>
#include <Sk/Rendering/Instance.hpp>
#include <stdexcept>

namespace Sk {
    Surface::Surface(Window& window, const Instance& instance)
        : instance{ instance.getVkInstance() }
    {
        auto glfwwindow{ window.getGLFWwindow() };

        if (glfwCreateWindowSurface(this->instance, glfwwindow, nullptr, &surface) != VK_SUCCESS) {
            throw std::runtime_error{ "failed to create window surface. " };
        }
    }

    Surface::~Surface() {
        vkDestroySurfaceKHR(instance, surface, nullptr);
    }
}