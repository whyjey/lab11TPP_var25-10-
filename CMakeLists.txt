cmake_minimum_required(VERSION 3.20)
project(Lab11_TPP_Var25 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/W4 /utf-8)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_executable(part1_lambdas src/part1_lambdas.cpp)
add_executable(part2_functors src/part2_functors.cpp)
add_executable(part3_immutability src/part3_immutability.cpp)
add_executable(part4_pipelines src/part4_pipelines.cpp)
add_executable(part5_errors src/part5_errors.cpp)
add_executable(part6_bonus src/part6_bonus.cpp)
