cmake_minimum_required(VERSION 3.9)
project(SkylineEngine)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/Cmake")
find_package(Vulkan REQUIRED)

add_subdirectory(Sources)
add_subdirectory(Examples)