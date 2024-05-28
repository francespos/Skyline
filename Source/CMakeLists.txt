add_library(Skyline STATIC Math/SkMatrix2.c Math/SkMatrix3.c Math/SkVector2.c Math/SkVector3.c)
set_property(TARGET Skyline PROPERTY C_STANDARD 99)

target_include_directories(Skyline STATIC ${CMAKE_SOURCE_DIR}/Includes)
