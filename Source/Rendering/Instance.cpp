#include <Sk/Rendering/Instance.hpp>
#include <stdexcept>

namespace Sk {
    Instance::Instance(std::string_view applicationName, std::uint32_t majorVersion, std::uint32_t minorVersion, std::uint32_t patchVersion) {
        VkApplicationInfo applicationInfo{
            .sType{ VK_STRUCTURE_TYPE_APPLICATION_INFO },
            .pApplicationName{ applicationName.data() },
            .applicationVersion{ VK_MAKE_VERSION(majorVersion, minorVersion, patchVersion) },
            .pEngineName{ "Skiline Engine" },
            .engineVersion{ VK_MAKE_VERSION(1, 0, 0) },
            .apiVersion{ VK_API_VERSION_1_0 }
        };

        VkInstanceCreateInfo createInfo{
            .sType{ VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO },
            .pApplicationInfo{ &applicationInfo }
        };

        if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
            throw std::runtime_error("failed to create instance.");
        }
    }

    Instance::~Instance() {
        vkDestroyInstance(instance, nullptr);
    }
}