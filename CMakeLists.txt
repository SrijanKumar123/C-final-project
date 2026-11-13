cmake_minimum_required(VERSION 3.16)

project(C_final_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(C_final_project main.cpp
        Fight.cpp
        Fight.h
        Fighter.cpp
        Fighter.h
        FightSimulator.cpp
        FightSimulator.h
        Striker.cpp
        Striker.h
        Grappler.cpp
        Grappler.h)