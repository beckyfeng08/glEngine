add_library(library STATIC test.cpp)
target_include_directories(library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})