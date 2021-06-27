cmake_minimum_required(VERSION 3.10)

set(PROJECT_ROOT ${CMAKE_SOURCE_DIR})

project(FlowEngine)

add_subdirectory(3rd-party/glfw)

include_directories(
    src
    src/FlowEngine
    3rd-party/glad/include
    3rd-party/glfw/include
    3rd-party/glm
)

file (GLOB_RECURSE FLOW_ENGINE CONFIGURE_DEPENDS
    src/FlowEngine/*.h
    src/FlowEngine/*.cpp
)

find_package(OpenGL REQUIRED)

link_libraries(
        glfw
        ${OPENGL_LIBRARY}
        )

add_executable(demo
    "src/demo.cpp"
    3rd-party/glad/lib/glad.c
    ${FLOW_ENGINE})

