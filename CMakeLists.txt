cmake_minimum_required(VERSION 3.14)
project(PassGen VERSION 0.1 LANGUAGES CXX)

set(CORE_SOURCES ./src/main.cxx ./src/passgen.cxx)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(PkgConfig)

if (NOT DEFINED USE_GTK)
    set(USE_GTK 0)
endif(NOT DEFINED USE_GTK)

if (NOT DEFINED USE_NCURSES)
    set(USE_NCURSES 0)
endif(NOT DEFINED USE_NCURSES)

if (${USE_GTK})
    pkg_check_modules(GTKMM gtkmm-4.0)
    include_directories(${GTKMM_INCLUDE_DIRS})
    link_directories(${GTKMM_LIBRARY_DIRS})
    set(GTK_SOURCES ./src/gtkui.cxx)
endif(${USE_GTK})

if (${USE_NCURSES})
    find_package(Curses REQUIRED)
    find_library(MENU_LIBRARY menu)
    find_library(FORM_LIBRARY form)
    include_directories(${CURSES_INCLUDE_DIR})
    set(NCURSES_SOURCES ./src/ncursesui.cxx)
endif(${USE_NCURSES})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/include/config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/include/config.h @ONLY)
add_executable(${PROJECT_NAME} ${CORE_SOURCES} ${GTK_SOURCES} ${NCURSES_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC
    ./include
)

if (${USE_GTK})
    target_link_libraries(${PROJECT_NAME} ${GTKMM_LIBRARIES})
endif(${USE_GTK})

if(${USE_NCURSES})
    target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARY} ${MENU_LIBRARY} ${FORM_LIBRARY})
endif(${USE_NCURSES})
