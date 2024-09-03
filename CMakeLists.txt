cmake_minimum_required(VERSION 3.5)
project("LinuxPlayground"  LANGUAGES CXX)

#cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..


#Chapter 00 -> origin
add_subdirectory(chapter_00)

add_subdirectory(chapter_01)

add_subdirectory(chapter_02)

add_subdirectory(chapter_03)

add_subdirectory(chapter_04)

add_subdirectory(chapter_05)
add_subdirectory(chapter_05_fibonacci_metaprogramming)
add_subdirectory(chapter_05_fibonacci_runtime)

add_subdirectory(chapter_06)

add_subdirectory(chapter_07)