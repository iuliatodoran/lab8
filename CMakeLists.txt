cmake_minimum_required(VERSION 3.21)
project(Lab8)

set(CMAKE_CXX_STANDARD 14)

include_directories(Lab8_MIR/Lab8_MIR)

add_executable(Lab8
        Lab8_MIR/Lab8_MIR/dayExpense.cpp
        Lab8_MIR/Lab8_MIR/dayExpense.h
        Lab8_MIR/Lab8_MIR/EntityTests.cpp
        Lab8_MIR/Lab8_MIR/EntityTests.h
        Lab8_MIR/Lab8_MIR/Expenses.cpp
        Lab8_MIR/Lab8_MIR/Expenses.h
        Lab8_MIR/Lab8_MIR/main.cpp
        Lab8_MIR/Lab8_MIR/RepoTests.cpp
        Lab8_MIR/Lab8_MIR/RepoTests.h
        Lab8_MIR/Lab8_MIR/Service.cpp
        Lab8_MIR/Lab8_MIR/Service.h
        Lab8_MIR/Lab8_MIR/ServiceTest.cpp
        Lab8_MIR/Lab8_MIR/ServiceTest.h
        Lab8_MIR/Lab8_MIR/UI.cpp
        Lab8_MIR/Lab8_MIR/UI.h)
