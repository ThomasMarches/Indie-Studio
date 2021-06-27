# Usage:
# FIND_PACKAGE(reflect REQUIRED)
# [...]
# TARGET_LINK_LIBRARIES(target_name reflect)

CMAKE_MINIMUM_REQUIRED(VERSION 3.11)

if (NOT reactphysics3d_FOUND)
  INCLUDE(FetchContent)

  set(RP3D_COMPILE_TESTBED OFF CACHE BOOL "")

  FetchContent_Declare(reactphysics3d
    GIT_REPOSITORY "https://github.com/DanielChappuis/reactphysics3d.git"
    GIT_TAG master GIT_SUBMODULES ""
  )
  FetchContent_GetProperties(reactphysics3d)

  if (NOT reactphysics3d_POPULATED)
    SET(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(reactphysics3d)
    ADD_SUBDIRECTORY(${reactphysics3d_SOURCE_DIR} ${reactphysics3d_BINARY_DIR})
    SET(reactphysics3d_FOUND TRUE)
  endif()
endif()
