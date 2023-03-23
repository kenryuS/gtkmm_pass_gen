cmake_minimum_required(VERSION 3.14)
project(APCSPCreateTask VERSION 0.1 LANGUAGES CXX)

set(SOURCE_DIR ./src)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-4.0)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_executable(APCSPCreateTask ${SOURCE_DIR}/main.cxx ${SOURCE_DIR}/passgen.cxx ${SOURCE_DIR}/gtkui.cpp)
target_link_libraries(APCSPCreateTask ${GTKMM_LIBRARIES})
target_include_directories(APCSPCreateTask PUBLIC
    include
)
