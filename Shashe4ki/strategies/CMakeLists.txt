project(strategies)
set(SOURCES
        standardrules.cpp
        computerlogic.cpp
        field.cpp)
set(HEADERS
        standardrules.h
        computerlogic.h
        field.h)

include_directories(../)

add_library(strategies ${SOURCES} ${HEADERS})
