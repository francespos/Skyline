#include <Sk/Rendering/PhysicalDevice.hpp>
#include <Sk/Rendering/Instance.hpp>
#include <stdexcept>
#include <vector>

namespace Sk {
    bool QueueFamilyIndices::isComplete() const {
        return graphicsFamily.has_value();
    }

    PhysicalDevice::PhysicalDevice(const Instance& instance) {
        const auto vkInstance{ instance.getVkInstance() };
        std::uint32_t deviceCount{ 0 };

        vkEnumeratePhysicalDevices(vkInstance, &deviceCount, nullptr);

        if (deviceCount == 0) {
            throw std::runtime_error{ "failed to find GPUs with Vulkan support." };
        }

        std::vector<VkPhysicalDevice> devices{ deviceCount };
        vkEnumeratePhysicalDevices(vkInstance, &deviceCount, devices.data());

        for (const auto& device : devices) {
            if (isDeviceSuitable(device)) {
                physicalDevice = device;
                break;
            }
        }

        if (physicalDevice == VK_NULL_HANDLE) {
            throw std::runtime_error{ "failed to find a suitable GPU." };
        }
    }

    bool PhysicalDevice::isDeviceSuitable(VkPhysicalDevice device) {
        const auto indices{ findQueueFamilies(device) };
        return indices.isComplete();
    }

    QueueFamilyIndices PhysicalDevice::findQueueFamilies(VkPhysicalDevice device) {
        QueueFamilyIndices indices{};

        std::uint32_t queueFamilyCount{ 0 };
        vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

        std::vector<VkQueueFamilyProperties> queueFamilies{ queueFamilyCount };
        vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

        auto i{ 0 };

        for (const auto& queueFamily : queueFamilies) {
            if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
                indices.graphicsFamily = i;
            }

            if (indices.isComplete()) {
                break;
            }

            ++i;
        }

        return indices;
    }
}