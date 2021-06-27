# Usage:
# FIND_PACKAGE(reflect REQUIRED)
# [...]
# TARGET_LINK_LIBRARIES(target_name reflect)

CMAKE_MINIMUM_REQUIRED(VERSION 3.11)

if (NOT reflect_FOUND)
  INCLUDE(FetchContent)

  FetchContent_Declare(reflect
    GIT_REPOSITORY "https://github.com/smbss1/reflect.git"
    GIT_TAG main
  )
  FetchContent_GetProperties(reflect)

  if (NOT reflect_POPULATED)
    SET(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(reflect)
    SET(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    ADD_SUBDIRECTORY(${reflect_SOURCE_DIR} ${reflect_BINARY_DIR})
    SET(reflect_FOUND TRUE)
  endif()
endif()
