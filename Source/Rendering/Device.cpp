#include <Sk/Rendering/Device.hpp>
#include <stdexcept>

namespace Sk {
    Device::Device(const PhysicalDevice& physicalDevice) {
        const auto indices{ PhysicalDevice::findQueueFamilies(physicalDevice.getVkPhysicalDevice()) };
        auto queuePriority{ 1.0f };

        const VkDeviceQueueCreateInfo queueCreateInfo{
            .sType{ VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO },
            .queueFamilyIndex{ indices.graphicsFamily.value() },
            .queueCount{ 1 },
            .pQueuePriorities{ &queuePriority }
        };

        const VkPhysicalDeviceFeatures deviceFeatures{};

        const VkDeviceCreateInfo createInfo{
            .sType{ VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO },
            .queueCreateInfoCount{ 1 },
            .pQueueCreateInfos{ &queueCreateInfo },
            .enabledLayerCount{ 0 },
            .pEnabledFeatures{ &deviceFeatures },
        };

        if (vkCreateDevice(physicalDevice.getVkPhysicalDevice()
            , &createInfo, nullptr, &device) != VK_SUCCESS) 
        {
            throw std::runtime_error{ "failed to create logical device." };
        }

        vkGetDeviceQueue(device, indices.graphicsFamily.value(), 0, &graphicsQueue);
    }

    Device::~Device() {
        vkDestroyDevice(device, nullptr);
    }
}