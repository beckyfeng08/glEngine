cmake_minimum_required(VERSION 3.31.2)
project(librarytest)

add_subdirectory(lib)


add_executable(${PROJECT_NAME}  src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE library)
