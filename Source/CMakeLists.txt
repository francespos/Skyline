add_library(Skyline STATIC "Math/Matrix.cpp" "Math/Vector.cpp" "Math/Transform.cpp")
set_property(TARGET Skyline PROPERTY CXX_STANDARD 11)
target_include_directories(Skyline PUBLIC ${CMAKE_SOURCE_DIR}/Include)
