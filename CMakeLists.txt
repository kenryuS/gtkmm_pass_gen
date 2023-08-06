cmake_minimum_required(VERSION 3.14)
project(APCSPCreateTask VERSION 0.1 LANGUAGES CXX)

set(SOURCE_DIR ./src)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PkgConfig)

if (${USE_GTK})
    pkg_check_modules(GTKMM gtkmm-4.0)
    include_directories(${GTKMM_INCLUDE_DIRS})
    link_directories(${GTKMM_LIBRARY_DIRS})
endif(${USE_GTK})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/include/config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/include/config.h @ONLY)
add_executable(${PROJECT_NAME} ${SOURCE_DIR}/main.cxx ${SOURCE_DIR}/passgen.cxx ${SOURCE_DIR}/gtkui.cxx)
target_include_directories(${PROJECT_NAME} PUBLIC
    include
)
if (${USE_GTK})
    target_link_libraries(${PROJECT_NAME} ${GTKMM_LIBRARIES})
endif(${USE_GTK})
