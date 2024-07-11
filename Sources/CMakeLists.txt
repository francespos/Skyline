add_library(Skyline STATIC "Math/Vector2.cpp")
set_property(TARGET Skyline PROPERTY CXX_STANDARD 17)

target_link_libraries(Skyline PRIVATE Vulkan::Vulkan)
target_include_directories(Skyline PUBLIC ${CMAKE_SOURCE_DIR}/Includes)