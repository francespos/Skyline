#pragma once

#include <vulkan/vulkan.h>

namespace Sk {
    class PhysicalDevice;

    class Device {
    public:
        explicit Device(const PhysicalDevice& physicalDevice);
        ~Device();
    private:
        VkDevice device{};
        VkQueue graphicsQueue{};
    };
}