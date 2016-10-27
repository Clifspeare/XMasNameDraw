cmake_minimum_required(VERSION 2.6)
project(drawnames)

add_executable(drawnames main.cpp)

install(TARGETS drawnames RUNTIME DESTINATION bin)
