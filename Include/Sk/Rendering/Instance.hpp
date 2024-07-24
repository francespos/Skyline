#pragma once

#include <vulkan/vulkan.h>
#include <string_view>
#include <cstdint>

namespace Sk {
    class Instance {
    public:
        explicit Instance(std::string_view applicationName, std::uint32_t majorVersion, std::uint32_t minorVersion, std::uint32_t patchVersion);
        ~Instance();

        VkInstance getVkInstance() const;
    private:
        VkInstance instance;
    };
}