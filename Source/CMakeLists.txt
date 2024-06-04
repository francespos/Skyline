add_library(Skyline INTERFACE)
set_property(TARGET Skyline PROPERTY CXX_STANDARD 20)
target_include_directories(Skyline INTERFACE ${CMAKE_SOURCE_DIR}/Include)
