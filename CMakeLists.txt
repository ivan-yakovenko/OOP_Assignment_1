cmake_minimum_required(VERSION 3.28)
project(OOP_Assignment_1)

set(CMAKE_CXX_STANDARD 26)

add_executable(OOP_Assignment_1 main.cpp
        Airplane/Airplane.cpp
        Airplane/Airplane.h
        Ticket/Ticket.cpp
        Ticket/Ticket.h)
