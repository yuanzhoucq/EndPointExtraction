cmake_minimum_required(VERSION 3.15)
project(EndPointExtraction)

find_package(OpenCV)
include_directories( ${OpenCV_INCLUDE_DIRS} )
set(CMAKE_CXX_STANDARD 11)

add_executable(EndPointExtraction main.cpp)
target_link_libraries(EndPointExtraction ${OpenCV_LIBS} )