add_library(Skyline INTERFACE)
set_property(TARGET Skyline PROPERTY CXX_STANDARD 11)
target_include_directories(Skyline INTERFACE ${CMAKE_SOURCE_DIR}/Include)
