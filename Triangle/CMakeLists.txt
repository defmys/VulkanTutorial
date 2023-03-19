cmake_minimum_required(VERSION 3.19.0)

set(target Triangle)

add_executable(${target} main.cpp application.cpp)

target_include_directories(${target} PRIVATE ${lib_root_dir}/stb ${lib_root_dir}/tinyobjloader)
target_link_libraries(${target} ${glfw} ${vulkan})
add_dependencies(${target} CompileShaders CopyResources)

add_custom_target(
    CompileShaders
    COMMAND glslc ${CMAKE_CURRENT_LIST_DIR}/shaders/shader.vert -o ${CMAKE_CURRENT_BINARY_DIR}/vert.spv
    COMMAND glslc ${CMAKE_CURRENT_LIST_DIR}/shaders/shader.frag -o ${CMAKE_CURRENT_BINARY_DIR}/frag.spv
)

add_custom_target(
    CopyResources
    COMMAND mkdir -p ${CMAKE_CURRENT_BINARY_DIR}/textures/
    COMMAND mkdir -p ${CMAKE_CURRENT_BINARY_DIR}/models/
    COMMAND cp -f ${CMAKE_CURRENT_LIST_DIR}/textures/* ${CMAKE_CURRENT_BINARY_DIR}/textures/
    COMMAND cp -f ${CMAKE_CURRENT_LIST_DIR}/models/* ${CMAKE_CURRENT_BINARY_DIR}/models/
)
