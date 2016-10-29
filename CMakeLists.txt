cmake_minimum_required(VERSION 2.6)
project(drawnames)
set(CMAKE_CXX_FLAGS "-std=c++11")

add_library(exclusionhandler exclusionhandler.cpp)
add_library(namehandler namehandler.cpp)
add_executable(drawnames main.cpp)
target_link_libraries(drawnames exclusionhandler)
target_link_libraries(drawnames namehandler)

install(TARGETS drawnames RUNTIME DESTINATION bin)
