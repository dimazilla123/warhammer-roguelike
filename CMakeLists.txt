cmake_minimum_required(VERSION 3.1)

project(warhammer-roguelike)
set(CMAKE_CXX_STANDARD 17)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

include_directories(src)

set(GAME_SRC 
    src/main.cpp
    src/entity.cpp
    src/ascii_component.cpp
    src/control_component.cpp
    src/monster_control_component.cpp
    src/player_control_component.cpp
    src/map.cpp
    src/game.cpp
    src/move_event.cpp
    src/control_event.cpp
    src/close_event.cpp
    )

add_executable(game ${GAME_SRC})
target_link_libraries(game ${CURSES_LIBRARIES})
