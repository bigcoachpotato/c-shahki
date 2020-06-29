project(strategies)
set(SOURCES
        computerlogic.cpp
        computer_strategy_1.cpp
        computer_strategy_2.cpp
        Person_Interface.cpp
        )
set(HEADERS
        computerlogic.h
        basic_interface.h
        computer_strategy_1.h
        computer_strategy_2.h
        Person_Interface.h)

include_directories(../)

add_library(strategies ${SOURCES} ${HEADERS})