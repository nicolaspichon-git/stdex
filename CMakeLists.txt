# stdex/CMakeLists.txt

cmake_minimum_required(VERSION 3.15)

project(stdex
  VERSION 1.0.0
  LANGUAGES CXX
)

# ------------------------------------------------------------------------------
# C++ requirements (C++14 minimum)
# ------------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ------------------------------------------------------------------------------
# Options
# ------------------------------------------------------------------------------
option(STDEX_BUILD_TESTS "Build stdex boost testsuite" ON)

# ------------------------------------------------------------------------------
# stdex header-only library
# ------------------------------------------------------------------------------
add_library(stdex INTERFACE)
add_library(stdex::stdex ALIAS stdex)

target_include_directories(stdex
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
target_compile_features(stdex
  INTERFACE
    cxx_std_14
)

# ------------------------------------------------------------------------------
# Dependencies
# ------------------------------------------------------------------------------

# --- Boost (headers only, version check only)

set(Boost_NO_BOOST_CMAKE ON)
find_package(Boost 1.72 REQUIRED)

target_include_directories(stdex
  INTERFACE
    ${Boost_INCLUDE_DIRS}
)

# --- Eggs.Invoke (implementation / tests only, NOT public)

if(STDEX_BUILD_TESTS)
  if(EXISTS ${CMAKE_SOURCE_DIR}/external/eggs)
    add_subdirectory(external/eggs)
    set(STDEX_EGGS_TARGET Eggs::Invoke)
  else()
    find_package(EggsInvoke REQUIRED)
    set(STDEX_EGGS_TARGET Eggs::Invoke)
  endif()
endif()

# ------------------------------------------------------------------------------
# Installation
# ------------------------------------------------------------------------------
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

install(
  DIRECTORY include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
  TARGETS stdex
  EXPORT stdexTargets
)

install(
  EXPORT stdexTargets
  NAMESPACE stdex::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/stdex
)

configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/stdexConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/stdexConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/stdex
)

install(
  FILES
    ${CMAKE_CURRENT_BINARY_DIR}/stdexConfig.cmake
  DESTINATION
    ${CMAKE_INSTALL_LIBDIR}/cmake/stdex
)

# ------------------------------------------------------------------------------
# Tests
# ------------------------------------------------------------------------------

if(STDEX_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
