#pragma once

#include <vulkan/vulkan.h>

namespace Sk {
    class Window;
    class Instance;

    class Surface {
    public:
        Surface(Window& window, const Instance& instance);
        ~Surface();
    private:
        VkSurfaceKHR surface{};
        VkInstance instance;
    };
}