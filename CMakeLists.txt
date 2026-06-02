cmake_minimum_required(VERSION 4.2)
project(Solver1D_TuyereLaval)

set(CMAKE_CXX_STANDARD 17)

add_executable(Solver1D_TuyereLaval main.cpp
        src/StateVector.h
        src/NumericalSchemes.h
        src/NumericalSchemes.cpp
        src/Cellule.h
        src/Cellule.cpp
        src/Domaine.h
        src/Domaine.cpp)
