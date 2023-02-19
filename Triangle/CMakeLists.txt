cmake_minimum_required(VERSION 3.19.0)

set(target Triangle)

add_executable(${target} main.cpp application.cpp)

target_link_libraries(${target} ${glfw} ${vulkan})
add_dependencies(${target} CompileShaders)

add_custom_target(
    CompileShaders
    COMMAND glslc ${CMAKE_CURRENT_LIST_DIR}/shaders/shader.vert -o ${CMAKE_CURRENT_BINARY_DIR}/vert.spv
    COMMAND glslc ${CMAKE_CURRENT_LIST_DIR}/shaders/shader.frag -o ${CMAKE_CURRENT_BINARY_DIR}/frag.spv
)
