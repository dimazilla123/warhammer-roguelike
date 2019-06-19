cmake_minimum_required(VERSION 3.1)

project(chiki_briki)
set(CMAKE_CXX_STANDARD 17)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

include_directories(src)

set(GAME_SRC 
    src/main.cpp
    src/entity.cpp
    src/ascii_component.cpp
    )

add_executable(game ${GAME_SRC})
target_link_libraries(game ${CURSES_LIBRARIES})
