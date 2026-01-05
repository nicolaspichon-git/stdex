cmake_minimum_required(VERSION 3.15)

project(stdex
  VERSION 1.0.0
  LANGUAGES CXX
)

# ------------------------------------------------------------------------------
# Library interface
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

# --- Boost dependency
find_package(Boost 1.72 REQUIRED)
target_include_directories(stdex
  INTERFACE
    ${Boost_INCLUDE_DIRS}
)

# --- Eggs.Invoke
if(EXISTS ${CMAKE_SOURCE_DIR}/external/eggs)
  add_subdirectory(external/eggs)
else()
  find_package(EggsInvoke REQUIRED)
endif()
target_link_libraries(stdex INTERFACE Eggs::Invoke)

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
# option(BUILD_TESTS "Build unit tests" ON)

# if(BUILD_TESTS)
#   enable_testing()

#   # Ajouter tous les tests dans le répertoire test/
#   file(GLOB TEST_SOURCES tests/*.cpp)
#   foreach(test_src ${TEST_SOURCES})
#     get_filename_component(test_name ${test_src} NAME_WE)
#     add_executable(${test_name} ${test_src})
#     target_link_libraries(${test_name} PRIVATE stdex Boost::unit_test_framework)
#     add_test(NAME ${test_name} COMMAND ${test_name})
#   endforeach()
# endif()
