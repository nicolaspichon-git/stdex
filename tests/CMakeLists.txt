# stdex/tests/CMakeLists.txt

# Collect test sources (exclude main)
file(GLOB_RECURSE STDEX_TEST_SOURCES
    CONFIGURE_DEPENDS
        "*.cpp"
)

list(REMOVE_ITEM STDEX_TEST_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/stdex_boost_testsuite_main.cpp"
)

# Executable test
add_executable(stdex_boost_testsuite
    stdex_boost_testsuite_main.cpp
    ${STDEX_TEST_SOURCES}
)

# include headers
target_include_directories(stdex_boost_testsuite
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/libs
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/dataset
)

# Link stdex
target_link_libraries(stdex_boost_testsuite
    PRIVATE
        stdex
)

target_compile_features(stdex_boost_testsuite
    PRIVATE
        cxx_std_14)

set_target_properties(stdex_boost_testsuite
    PROPERTIES
        CXX_EXTENSIONS OFF
)

target_include_directories(stdex_boost_testsuite
    PRIVATE
        ${CMAKE_SOURCE_DIR}/external/eggs/include
)

# CTest
add_test(
    NAME stdex_boost_testsuite
    COMMAND stdex_boost_testsuite
)
