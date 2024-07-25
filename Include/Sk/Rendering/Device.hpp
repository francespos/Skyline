#pragma once

#include <Sk/Rendering/PhysicalDevice.hpp>

namespace Sk {
    class Device {
    public:
        explicit Device(const PhysicalDevice& physicalDevice);
        ~Device();
    private:
        VkDevice device{};
        VkQueue graphicsQueue{};
    };
}