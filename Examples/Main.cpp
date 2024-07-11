#include <iostream>
#include <Sk/Math/Vector2.hpp>
#include <GLFW/glfw3.h>

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
    auto window{ glfwCreateWindow(800, 800, "Skyline", nullptr, nullptr) };

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    std::cout << "Test completed successfully.";
}