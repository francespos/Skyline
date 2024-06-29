cmake_minimum_required(VERSION 3.9)
project(SkylineEngine)

find_package(Vulkan REQUIRED)

add_subdirectory(Library)
add_subdirectory(Source)
add_subdirectory(Test)