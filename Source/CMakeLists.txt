add_library(Skyline STATIC "Math/Vector2.cpp" "Rendering/Instance.cpp" "Rendering/PhysicalDevice.cpp" "Rendering/Device.cpp" "Rendering/Surface.cpp" "Context/Context.cpp" "Context/Window.cpp")
target_link_libraries(Skyline PUBLIC Vulkan::Vulkan ${GLFW3_LIBRARY})
target_include_directories(Skyline PUBLIC ${CMAKE_SOURCE_DIR}/Include ${GLFW3_INCLUDE_DIR})