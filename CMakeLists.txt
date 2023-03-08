cmake_minimum_required(VERSION 3.19.0)

project(vk_tutorial)
set(project_root_dir ${CMAKE_CURRENT_LIST_DIR})
set(lib_root_dir ${project_root_dir}/libs)

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
    -std=c++20 \
    -Wall \
    -Werror \
    -I/usr/local/include \
    -I/opt/homebrew/include \
    ")

find_library(glfw glfw REQIURED)
find_library(vulkan vulkan REQUIRED)

add_subdirectory( VulkanTesting )
add_subdirectory( Triangle )
