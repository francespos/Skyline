#pragma once

#include <cstdint>
#include <vulkan/vulkan.h>
#include <optional>

namespace Sk {
    class Instance;

    struct QueueFamilyIndices {
        std::optional<std::uint32_t> graphicsFamily;
        bool isComplete() const;
    };

    class PhysicalDevice {
    public:
        explicit PhysicalDevice(const Instance& instance);
    private:
        static bool isDeviceSuitable(VkPhysicalDevice device);
        static QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

        VkPhysicalDevice physicalDevice{ VK_NULL_HANDLE };
    };
}