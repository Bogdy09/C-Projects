cmake_minimum_required(VERSION 3.27)
project(t2_real_estate_agency)

set(CMAKE_CXX_STANDARD 17)

add_executable(t2_real_estate_agency main.cpp
        client.h
        client.cpp
        dwelling.h
        dwelling.cpp
        real_estate_agency.h
        real_estate_agency.cpp
        UI.h
        UI.cpp)
