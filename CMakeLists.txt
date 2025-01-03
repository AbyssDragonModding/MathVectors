cmake_minimum_required(VERSION 3.30)
project(MathVectors)

add_library(MathVectors INTERFACE)
target_include_directories(MathVectors INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(vector_example examples/example_vector.cpp)
target_link_libraries(vector_example MathVectors)
