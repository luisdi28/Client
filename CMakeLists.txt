cmake_minimum_required(VERSION 3.23)
project(Client)
find_package( OpenCV REQUIRED )
include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 14)



add_executable(Client
        Cliente.cpp
        Cliente.h)
target_link_libraries( Client ${OpenCV_LIBS} )
