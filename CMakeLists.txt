cmake_minimum_required(VERSION 3.9)
project(SkylineEngine)

find_package(Vulkan REQUIRED)

add_subdirectory(Libraries)
add_subdirectory(Sources)
add_subdirectory(Examples)