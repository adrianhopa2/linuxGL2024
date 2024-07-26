cmake_minimum_required(VERSION 3.5)
set(APPNAME "Chapter_05_Fibonacci_Runtime")
set (CMAKE_CXX_STANDARD 20)

set (SOURCES
    src/main.cpp
)

set(HEADERS
)

project(${APPNAME}  LANGUAGES CXX)
add_executable(${APPNAME} ${HEADERS} ${SOURCES} )

include_directories(src)