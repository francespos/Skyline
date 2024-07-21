add_executable(Main "Main.cpp")

find_package(GLFW3 REQUIRED)
message(STATUS "Found GLFW3 include directory in ${GLFW3_INCLUDE_DIR}")
message(STATUS "Found GLFW3 library in ${GLFW3_LIBRARY}")

target_link_libraries(Main PUBLIC Skyline ${GLFW3_LIBRARY})
target_include_directories(Main PUBLIC ${GLFW3_INCLUDE_DIR})