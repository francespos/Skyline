add_library(Skyline STATIC "Math/Translation.cpp" "Math/Rotation.cpp" "Math/Matrix.cpp" "Math/Vector.cpp" "Math/Float.cpp")
set_property(TARGET Skyline PROPERTY CXX_STANDARD 11)
target_include_directories(Skyline PUBLIC ${CMAKE_SOURCE_DIR}/Include)
