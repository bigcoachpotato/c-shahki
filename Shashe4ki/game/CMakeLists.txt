project(game)

set(SOURCES
        field.cpp
        game.cpp
        standardrules.cpp)
set(HEADERS
        field.h
        game.h
        standardrules.h)

include_directories(../)

add_library(game ${SOURCES} ${HEADERS})