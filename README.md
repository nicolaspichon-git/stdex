# Stdex Library

**Stdex** is a header-only C++ library providing post-C++14 features for C++14 compilers. 

## Features

See [the documentation page](docs/StdexIndex.md).

## Usage
In your target's `CMakeLists.txt` file:
```cmake
find_package(stdex REQUIRED)
target_link_libraries(my_target PRIVATE stdex::stdex)
```

## Requirements

- C++14 or later
- CMake ≥ 3.15
- Optional:
    - Boost ≥ 1.72 (for stdex::any, stdex::variant, stdex::optional)
    - Eggs.Invoke ≥ 1.0 (for stdex::invoke)

## Dependencies
- Compiles with C++14 compilers and later versions.
- Depends on STL library.
- May depend on [**Boost**](https://www.boost.org/libraries/latest/grid/) libraries (on C++14 compilers): 
Boost.Utility, Boost.Optional, Boost.Variant2.
- May depend on [**Eggs.Invoke**](https://eggs-cpp.github.io/invoke/) library (on C++14 compilers).
