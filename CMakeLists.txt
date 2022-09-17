cmake_minimum_required(VERSION 3.23)
project(Client)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Client
        Cliente.cpp
        Cliente.h)
