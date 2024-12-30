cmake_minimum_required(VERSION 3.31.2)
project(glEngine)


add_executable(${PROJECT_NAME}  src/main.cpp)


find_package(GLEW REQUIRED)

add_subdirectory(lib)
add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME} PUBLIC lib PUBLIC external/glfw/include)

target_link_libraries(${PROJECT_NAME} PRIVATE library PRIVATE glfw)
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})
