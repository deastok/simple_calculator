cmake_minimum_required(VERSION 4.0)
project(math)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(math
        src/app.cpp
        src/calculator.cpp
)
