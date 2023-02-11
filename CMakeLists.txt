cmake_minimum_required(VERSION 3.19.0)

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
    -std=c++20 \
    -Wall \
    -Werror \
    -I/usr/local/include \
    -I/opt/homebrew/include \
    ")

project(vk_tutorial)

set( target vk_tutorial )

add_executable(${target} main.cpp)

find_library(glfw glfw REQIURED)
find_library(vulkan vulkan REQUIRED)
target_link_libraries(${target} ${glfw} ${vulkan})
