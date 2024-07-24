#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <Sk/Math/Vector2.hpp>
#include <Sk/Rendering/Instance.hpp>
#include <Sk/Rendering/PhysicalDevice.hpp>

std::ostream& operator<<(std::ostream& out, const Sk::Vector2& v) {
    out << "[" << v.x << ", " << v.y << "]";
    return out;
}

int main() {
    Sk::Vector2 v1{ 1.0f, 2.0f };
    Sk::Vector2 v2{ 4.0f, 5.0f };

    std::cout << "v1 = " << v1 << "\n";
    std::cout << "v2 = " << v2 << "\n";

    std::cout << "v1[0] = " << v1[0] << "\n";
    std::cout << "v1[1] = " << v1[1] << "\n";

    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    auto window{ glfwCreateWindow(800, 800, "Skyline", nullptr, nullptr) };

    Sk::Instance instance{ "example", 1, 0, 0 };
    Sk::PhysicalDevice physicalDevice{ instance };

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    std::cout << "Test completed successfully.";
}