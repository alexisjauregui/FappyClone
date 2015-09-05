cmake_minimum_required(VERSION 3.2)
project(Flappy1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Flappy1 ${SOURCE_FILES} game_state.h game.cpp game.h main_state.cpp main_state.h bird.cpp bird.h background.cpp background.h Score.cpp Score.h Pipes.cpp Pipes.h collisions.cpp collisions.h )

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Flappy1 ${SFML_LIBRARIES})
endif()
