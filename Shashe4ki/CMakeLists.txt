cmake_minimum_required(VERSION 3.15)
project(Shashe4ki)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES main.cpp)

add_executable(Shashe4ki ${SOURCES})

add_subdirectory(strategies)
add_subdirectory(game)

target_link_libraries(Shashe4ki strategies game)