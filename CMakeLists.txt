cmake_minimum_required(VERSION 3.31.2)
project(glEngine)
set(CMAKE_CXX_STANDARD 11)

add_executable(${PROJECT_NAME}  
    src/main.cpp 
    src/IndexBuffer.cpp 
    src/VertexBuffer.cpp 
    src/Renderer.cpp
    src/VertexArray.cpp
    src/Shader.cpp
    src/Texture.cpp
    )

add_subdirectory(lib)
add_subdirectory(external/glfw)
add_subdirectory(external/glew)
add_subdirectory(external/stb_image)
add_subdirectory(external/glm)
add_subdirectory(external/imgui)

target_include_directories(${PROJECT_NAME} 
    PUBLIC lib 
    PUBLIC external/glfw/include
    PUBLIC external/glew/include 
    PUBLIC external/glm/glm 
    PUBLIC external/stb_image 
    PUBLIC external/imgui 
    PUBLIC src)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE library 
    PRIVATE glfw 
    PRIVATE glm 
    PRIVATE stb_im
    PRIVATE imgui
    PRIVATE libglew_static)