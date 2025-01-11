add_library(stb_im STATIC stb_image.cpp)
target_include_directories(stb_im PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})