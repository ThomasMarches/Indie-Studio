cmake_minimum_required(VERSION 3.17)

file(GLOB_RECURSE SRCS "src/*.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/..)

add_executable(bomberman ${SRCS})

target_include_directories(bomberman PRIVATE "include")
target_link_libraries(bomberman PUBLIC fox_engine)