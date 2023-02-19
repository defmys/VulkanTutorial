cmake_minimum_required(VERSION 3.19.0)

set(target Triangle)

add_executable(${target} main.cpp application.cpp)

target_link_libraries(${target} ${glfw} ${vulkan})
add_dependencies(${target} CompileShaders)

add_custom_target(
    CompileShaders
    COMMAND ${CMAKE_CURRENT_LIST_DIR}/compile_shaders.sh
)
