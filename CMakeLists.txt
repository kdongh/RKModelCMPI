cmake_minimum_required(VERSION 3.14)
project(RK_MPI)
set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES main.cpp complexNumber.cpp basis.cpp rungeKutta.cpp tdSch.cpp)

add_executable(out ${SOURCE_FILES})