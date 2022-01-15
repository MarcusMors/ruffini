# =============================================================================
# Preamble
# =============================================================================

cmake_minimum_required(VERSION 3.12)

project(
  ruffini_app
  VERSION 1.0.0
  DESCRIPTION "c++ ruffini decomposer console application"
  # HOMEPAGE_URL https://github.com/MarcusMors/cmake-template
)

#[============================================================================[
# Project wide setup
#]============================================================================]

option(BUILD_DOC "Build Documentation" OFF)

# Variables
set(PROJECT_SOURCE_DIR "src")
set(PROJECT_INCLUDE_DIR "include")

#[============================================================================[
# Main targets built by this project
#]============================================================================]

add_subdirectory(${PROJECT_INCLUDE_DIR})
add_subdirectory(${PROJECT_SOURCE_DIR})

if(BUILD_DOC)
  add_subdirectory(docs-building/docs-doxygen)
endif()

# Things only needed if we are the top level project if(CMAKE_SOURCE_DIR
# STREQUAL CMAKE_CURRENT_SOURCE_DIR) add_subdirectory(tests) #
# add_subdirectory(packaging) endif()

#[============================================================================[
Resources:
- https://medium.com/practical-coding/c-documentation-with-doxygen-cmake-sphinx-breathe-for-those-of-use-who-are-totally-lost-7d555386fe13
- https://medium.com/practical-coding/c-documentation-with-doxygen-cmake-sphinx-breathe-for-those-of-use-who-are-totally-lost-part-2-21f4fb1abd9f
- https://uva-cs.github.io/pdr/tutorials/11-doxygen/index.html

#]============================================================================]
