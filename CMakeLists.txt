cmake_minimum_required(VERSION 4.2)
project(MazeSolver)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.5
)
fetchcontent_makeavailable(raylib)

add_executable(MazeSolver main.cpp
        main.cpp
        main.cpp
        robot.cpp
        robot.h
        map.cpp
        map.h
        PathProcessing.cpp
        PathProcessing.h
        Utils.cpp
        Utils.h
)

target_link_libraries(MazeSolver raylib)