add_library(SkMath STATIC Matrix2.cpp Matrix3.cpp Vector2.cpp Vector3.cpp Scale.cpp Translation.cpp Rotation.cpp)
set_property(TARGET SkMath PROPERTY CXX_STANDARD 11)
target_include_directories(SkMath STATIC ${CMAKE_SOURCE_DIR}/Includes)
