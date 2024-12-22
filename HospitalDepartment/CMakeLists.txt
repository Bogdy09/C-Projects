cmake_minimum_required(VERSION 3.27)
project(t2_hospital_department)

set(CMAKE_CXX_STANDARD 17)

add_executable(t2_hospital_department main.cpp
        HospitalDepartment.h
        HospitalDepartment.cpp
        Services.h
        Services.cpp
        UI.h
        UI.cpp)
