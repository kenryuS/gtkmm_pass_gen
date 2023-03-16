cmake_minimum_required(VERSION 3.14)
project(APCSPCreateTask VERSION 0.1 LANGUAGES CXX)
set(SOURCE_DIR ./src)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_executable(APCSPCreateTask ${SOURCE_DIR}/main.cxx ${SOURCE_DIR}/passgen.cxx)
target_include_directories(APCSPCreateTask PUBLIC
    include
)
