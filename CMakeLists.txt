cmake_minimum_required(VERSION 3.31.2)
project(glEngine)

add_executable(${PROJECT_NAME}  
    src/main.cpp 
    src/IndexBuffer.cpp 
    src/VertexBuffer.cpp 
    src/Renderer.cpp
    src/VertexArray.cpp
    src/Shader.cpp)

add_subdirectory(lib)
add_subdirectory(external/glfw)
add_subdirectory(external/glew)

target_include_directories(${PROJECT_NAME} PUBLIC lib PUBLIC external/glfw/include PUBLIC external/glew/include PUBLIC src)

target_link_libraries(${PROJECT_NAME} PRIVATE library PRIVATE glfw PRIVATE libglew_static)