# stdex/tests/CMakeLists.txt

# Collect test sources (exclude main)
file(GLOB_RECURSE STDEX_TEST_SOURCES
    CONFIGURE_DEPENDS
        "*.cpp"
)

list(REMOVE_ITEM STDEX_TEST_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/stdex_boost_test_suite_main.cpp"
)

# Executable test
add_executable(stdex_boost_test_suite
    stdex_boost_test_suite_main.cpp
    ${STDEX_TEST_SOURCES}
)

# include headers
target_include_directories(stdex_boost_test_suite
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/dataset
)

# Link stdex
target_link_libraries(stdex_boost_test_suite
    PRIVATE
        stdex
)

target_compile_features(stdex_boost_test_suite
    PRIVATE
        cxx_std_14)

set_target_properties(stdex_boost_test_suite
    PROPERTIES
        CXX_EXTENSIONS OFF
)

target_include_directories(stdex_boost_test_suite
    PRIVATE
        ${CMAKE_SOURCE_DIR}/external/eggs/include
)

# CTest
add_test(
    NAME stdex_boost_test_suite
    COMMAND stdex_boost_test_suite
)
