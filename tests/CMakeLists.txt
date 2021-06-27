cmake_minimum_required(VERSION 3.17)

FILE(GLOB TEST_SRCS "*.cpp")

set(PROJECT_ROOT "..")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})


set(GTEST_VERSION 1.10.0 CACHE STRING "Google test version")
################################
# GTest
################################
FetchContent_Declare(googletest
        GIT_REPOSITORY "https://github.com/google/googletest.git"
        GIT_TAG release-${GTEST_VERSION}
        )

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

enable_testing()

################################
# Unit Tests
################################
# Add test cpp file
add_executable(unit_tests ${TEST_SRCS} ${BOMBER_SRCS})

# Include directories
target_include_directories(unit_tests PRIVATE
        $<TARGET_PROPERTY:gtest,INTERFACE_SYSTEM_INCLUDE_DIRECTORIES>
        $<TARGET_PROPERTY:gtest_main,INTERFACE_SYSTEM_INCLUDE_DIRECTORIES>
        ${BOMBER_INCLUDE})

# Link test executable against gtest & gtest_main
target_link_libraries(unit_tests gtest gtest_main fox_engine)

add_test(unit_tests unit_tests)