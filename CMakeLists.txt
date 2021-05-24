# EPITECH PROJECT, 2021
# B-YEP-400-TLS-4-1-indiestudio-martin.legrand
# File description:
# CMakeLists.txt
#

cmake_minimum_required(VERSION 3.17.2)

project(nanotekspice VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wfatal-errors -g3")

file(GLOB SRC "src/*.cpp")
file(GLOB SRC "src/chips/*.cpp")

add_executable(${PROJECT_NAME} ${SRC})

include_directories(
./include
./include/chips/
)