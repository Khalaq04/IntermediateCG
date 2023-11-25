cmake_minimum_required (VERSION 3.8)

project (IntermediateCG)

set(CMAKE_CXX_STANDARD 17)
#set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Project2)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

add_subdirectory(Project2)

add_subdirectory(vendor/GLFW)
target_include_directories(Project2 PRIVATE vendor/GLFW/include)
target_compile_definitions(Project2 PRIVATE GLFW_INCLUDE_NONE)

add_library(glad vendor/Glad/src/glad.c)
target_include_directories(glad PRIVATE vendor/Glad/include)
target_include_directories(Project2 PRIVATE vendor/Glad/include)