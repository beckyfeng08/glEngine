cmake_minimum_required(VERSION 3.31.2)
project(glEngine)


add_executable(${PROJECT_NAME}  src/main.cpp)

add_subdirectory(lib)
add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME} PUBLIC lib PUBLIC external/glfw/include)

target_link_libraries(${PROJECT_NAME} library glfw)
