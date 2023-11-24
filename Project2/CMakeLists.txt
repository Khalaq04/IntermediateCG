cmake_minimum_required (VERSION 3.8)

project(Project2)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/${PROJECT_NAME})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/${PROJECT_NAME})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${PROJECT_NAME})

add_executable(Project2 "src/Main.cpp" "src/Main.h" "../vendor/Glad/src/glad.c")

target_link_libraries(Project2
	PRIVATE glad
	PRIVATE glfw
	PRIVATE ${OPENGL_LIBRARIES}
	PRIVATE ${GLFW_LIBRARIES}
)

add_custom_command(
	TARGET Project2 PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${PROJECT_SOURCE_DIR}/assets/ $<TARGET_FILE_DIR:Project2>/assets)