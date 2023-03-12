cmake_minimum_required(VERSION 3.23)
project(oasis2)

set(CMAKE_CXX_STANDARD 14)

add_executable(oasis2 main.cpp board.cpp board.h monster.cpp monster.h player.cpp player.h field.cpp field.h game.cpp game.h)
