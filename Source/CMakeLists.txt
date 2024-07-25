add_library(Skyline STATIC "Math/Vector2.cpp" "Rendering/Instance.cpp" "Rendering/PhysicalDevice.cpp" "Rendering/Device.cpp")
target_link_libraries(Skyline PUBLIC Vulkan::Vulkan)
target_include_directories(Skyline PUBLIC ${CMAKE_SOURCE_DIR}/Include)