Stdex Library
=============

[TOC]

# Introduction

**Stdex** is a header-only library providing some C++ features that are not available yet in C++14.

The missing features could be already provided by C++17 or the experimental STL libraries. 
The library provides also a few non-standard components.

# Motivation
- You need some C++17 features like `std::string_view`, `std::in_place`, `std::as_const`, etc. 
- But your company is still stuck with C++14 and you are not even sure if it has planned to upgrade your compiler to an earler version. 

# Rationale
- Use the **Boost** library if it already provides the missing feature.
- Should compile equally with C++14 and C++17.
- Put all the missing features in the single `stdex` namespace.
- Standard components should still compile with C++17 when the `stdex` namespace name is replaced with `std`.

# Reference
```
stdex::as_const
stdex::in_place_t
stdex::in_place_type_t
stdex::void_t
stdex::negation
stdex::conjunction
stdex::disjunction
stdex::string_view
stdex::observer_ptr
stdex::static_constexpr
```

# Dependencies
- The library compiles with C++14 and later versions and depends only on STL.

# Building
\[...TODO...\]

# Version
\[...TODO...\]
