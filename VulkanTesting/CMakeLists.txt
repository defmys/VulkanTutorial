cmake_minimum_required(VERSION 3.19.0)

set( target VulkanTesting )

add_executable(${target} main.cpp)

target_link_libraries(${target} ${glfw} ${vulkan})
