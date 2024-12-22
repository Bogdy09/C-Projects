cmake_minimum_required(VERSION 3.27)
project(IoT)

set(CMAKE_CXX_STANDARD 17)

add_executable(IoT main.cpp
        Sensor.h
        Sensor.cpp
        Device.h
        Device.cpp
        UI.h
        UI.cpp)
