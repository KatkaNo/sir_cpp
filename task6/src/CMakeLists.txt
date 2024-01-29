add_library(Matrix STATIC matrix.cpp)
add_library(Gradient STATIC gradient.cpp)
target_include_directories(Matrix PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_include_directories(Gradient PUBLIC "${PROJECT_SOURCE_DIR}/include")
