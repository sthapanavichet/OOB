cmake_minimum_required(VERSION 3.25)
project(Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project PlayerMain_run.cpp Player.cpp Player.h PlayerYouth.h AdultPlayer.h PlayerMain.cpp CardGame.cpp CardGame.h)
