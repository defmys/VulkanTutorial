cmake_minimum_required(VERSION 3.19.0)

project(vk_tutorial)

set( target vk_tutorial )

add_executable(${target} main.cpp)

target_link_libraries(${target} ${glfw} ${vulkan})
