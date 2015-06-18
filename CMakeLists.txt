cmake_minimum_required(VERSION 3.2)
project(Project_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Project_1 ${SOURCE_FILES} Card.h Card.cpp Command.h Command.cpp Computer.h Computer.cpp Controller.h Controller.cpp Deck.h Deck.cpp Human.h Human.cpp Model.cpp Model.h Model.cpp Player.h Player.cpp View.h View.cpp TableCards.cpp TableCards.h)