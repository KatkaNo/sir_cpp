cmake_minimum_required (VERSION 3.8)
project ("GradConj CXX")

#add_subdirectory ("test")
add_subdirectory ("src")

add_executable(main "src/main.cpp" )
target_link_libraries(main Matrix)
target_link_libraries(main Gradient)
