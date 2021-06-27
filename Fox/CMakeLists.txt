cmake_minimum_required(VERSION 3.17)

file(GLOB_RECURSE CORE_SRCS "src/*.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(REFL_JSON 1)
set(THREADS_PREFER_PTHREAD_FLAG ON)

if(WIN32)
    list(APPEND CMAKE_PREFIX_PATH "C:\\Program Files (x86)\\ReactPhysics3D")
elseif(APPLE)
    list(APPEND CMAKE_PREFIX_PATH "/usr/local/lib/cmake/ReactPhysics3D")
endif()

find_package(raylib REQUIRED)
find_package(reactphysics3d REQUIRED)
find_package(foxjson REQUIRED)
find_package(Threads REQUIRED)

add_library(fox_engine STATIC ${CORE_SRCS})
target_include_directories(fox_engine PUBLIC "include")
target_link_libraries(fox_engine PUBLIC ${CMAKE_DL_LIBS} raylib reactphysics3d fox_json Threads::Threads)
target_compile_definitions(fox_engine PRIVATE FOX_BUILD_LIB=1)


if (False)
    find_package(reflect REQUIRED)
    target_link_libraries(fox_engine PUBLIC refl)
endif()