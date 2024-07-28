#include <iostream>
#include <stdexcept>
#include <Sk/Math/Vector2.hpp>
#include <Sk/Context/Context.hpp>
#include <Sk/Context/Window.hpp>
#include <Sk/Rendering/Instance.hpp>
#include <Sk/Rendering/Surface.hpp>
#include <Sk/Rendering/PhysicalDevice.hpp>
#include <Sk/Rendering/Device.hpp>

std::ostream& operator<<(std::ostream& out, const Sk::Vector2& v) {
    out << "[" << v[0] << ", " << v[1] << "]";
    return out;
}

int main() {
    Sk::Vector2 v1{ 1.0f, 2.0f };
    Sk::Vector2 v2{ 4.0f, 5.0f };

    std::cout << "v1 = " << v1 << "\n";
    std::cout << "v2 = " << v2 << "\n";

    std::cout << "v1[0] = " << v1[0] << "\n";
    std::cout << "v1[1] = " << v1[1] << "\n";

    auto context{ Sk::Context::getInstance() };
    Sk::Window window{ *context, 800, 800, "Skyline Example" };

    const Sk::Instance instance{ "example", 1, 0, 0 };
    const Sk::PhysicalDevice physicalDevice{ instance };
    const Sk::Device device{ physicalDevice };

    while (!window.shouldClose()) {
        context->pollEvents();
    }    

    std::cout << "Test completed successfully.";
}