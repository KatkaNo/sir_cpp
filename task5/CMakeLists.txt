cmake_minimum_required(VERSION 3.2)
project (LIST CXX)

add_subdirectory(src)

option(BUILD_TESTING "building tests" On)

enable_testing()
add_subdirectory(test)

