cmake_minimum_required(VERSION 3.10)
project(mtl LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)

# target_compile_features(mtl PRIVATE cxx_std_20)