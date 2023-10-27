cmake_minimum_required(VERSION 2.8.12)

project(CVmain)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(demo CVmain.cpp)
target_link_libraries(demo ${OpenCV_LIBS})