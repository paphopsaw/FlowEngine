cmake_minimum_required(VERSION 3.10)

set(PROJECT_ROOT ${CMAKE_SOURCE_DIR})


project(FlowEngine)

find_package(OpenGL REQUIRED)

include_directories(
    src
)

add_executable(demo
    src/main.cpp
    "src/Vector2D.cpp"
     "src/precision.h" "src/Vector3D.cpp" "src/Vector3D.h")