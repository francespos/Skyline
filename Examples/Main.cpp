#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <Sk/Math/Vector2.hpp>
#include <Sk/Rendering/Instance.hpp>
#include <Sk/Rendering/PhysicalDevice.hpp>
#include <Sk/Rendering/Device.hpp>

std::ostream& operator<<(std::ostream& out, const Sk::Vector2& v) {
    out << "[" << v.x << ", " << v.y << "]";
    return out;
}

int main() {
    Sk::Vector2 v1{ 1.0f, 2.0f };
    Sk::Vector2 v2{ 4.0f, 5.0f };

    std::cout << "v1 = " << v1 << "\n";
    std::cout << "v2 = " << v2 << "\n";

    std::cout << "v1.x = " << v1.x << "\n";
    std::cout << "v1.y = " << v1.y << "\n";

    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    auto window{ glfwCreateWindow(800, 800, "Skyline", nullptr, nullptr) };

    const Sk::Instance instance{ "example", 1, 0, 0 };
    const Sk::PhysicalDevice physicalDevice{ instance };
    const Sk::Device device{ physicalDevice };

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    std::cout << "Test completed successfully.";
}