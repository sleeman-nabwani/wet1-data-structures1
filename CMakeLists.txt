cmake_minimum_required(VERSION 3.22)
project(wet1_data_structures1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(wet1_data_structures1
        ActiveTeam.cpp
        ActiveTeam.h
        AVLTree.h
        main23a1.cpp
        Player.cpp
        Player.h
        PlayerById.cpp
        PlayerById.h
        PlayerByIdTeams.cpp
        PlayerByIdTeams.h
        Project1.cpp
        Team.cpp
        Team.h
        wet1util.h
        worldcup23a1.cpp
        worldcup23a1.h)
