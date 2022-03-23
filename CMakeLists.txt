cmake_minimum_required(VERSION 3.21)
project(HashMap)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
        "main.cpp"
        "HashMap.cpp")

add_executable(HashMap ${SOURCES})
