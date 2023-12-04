cmake_minimum_required(VERSION 3.2)
project (prime CXX)

add_subdirectory(src)
add_executable(main src/main.cpp)
target_link_libraries(main prime)
