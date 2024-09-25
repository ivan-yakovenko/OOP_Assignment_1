cmake_minimum_required(VERSION 3.28)
project(OOP_Assignment_1)

set(CMAKE_CXX_STANDARD 26)

add_executable(OOP_Assignment_1 Assignment_1/main.cpp
        Assignment_1/Airplane/Airplane.cpp
        Assignment_1/Airplane/Airplane.h
        Assignment_1/Ticket/Ticket.cpp
        Assignment_1/Ticket/Ticket.h
        Assignment_1/ConfigReader/ConfigReader.cpp
        Assignment_1/ConfigReader/ConfigReader.h
        Assignment_1/CLI/CLI.cpp
        Assignment_1/CLI/CLI.h
        Assignment_1/FileHandler/FileHandler.cpp
        Assignment_1/FileHandler/FileHandler.h
        Assignment_1/FileCloser/FileCloser.cpp
        Assignment_1/FileCloser/FileCloser.h)
