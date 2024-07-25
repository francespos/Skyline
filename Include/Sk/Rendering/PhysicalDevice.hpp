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

        static QueueFamilyIndices findQueueFamilies(VkPhysicalDevice vkPhysicalDevice);

        VkPhysicalDevice getVkPhysicalDevice() const;
    private:
        static bool isDeviceSuitable(VkPhysicalDevice vkPhysicalDevice);

        VkPhysicalDevice physicalDevice{ VK_NULL_HANDLE };
    };
}