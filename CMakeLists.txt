cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 17)

project(Ecs VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_CXX_FLAGS --coverage)

set(BOMBER_INCLUDE "${CMAKE_SOURCE_DIR}/game/include")
file(GLOB_RECURSE BOMBER_SRCS "game/src/*.cpp")

# Linux specific code
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_compile_definitions(FOX_PLATFORM_LINUX=1)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

# Windows specific code
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    add_compile_definitions(FOX_PLATFORM_WINDOWS=1)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")

add_subdirectory(Fox)
add_subdirectory(game)
add_subdirectory(tests)