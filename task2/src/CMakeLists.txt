add_library(prime STATIC num_primes.cpp)
target_include_directories(prime PUBLIC "${PROJECT_SOURCE_DIR}/include")