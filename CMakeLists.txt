cmake_minimum_required(VERSION 3.10)

project(nanotekspice VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set( PROJECT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR} )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++14 -Wfatal-errors -Wl,--no-as-needed -ldl")
file(GLOB SRC
     "src/*.cpp"
     "src/chips/*.cpp"
)

add_executable(${PROJECT_NAME} ${SRC})
include_directories( include )

target_include_directories(nanotekspice PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )