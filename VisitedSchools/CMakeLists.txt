cmake_minimum_required(VERSION 3.27)
project(school_test1)

set(CMAKE_CXX_STANDARD 17)

add_executable(school_test1 main.cpp
        domain.h
        domain.cpp
        dynamic_array.h
        dynamic_array.cpp
        repository.h
        repository.cpp
        services.h
        services.cpp
        UI.h
        UI.cpp)
