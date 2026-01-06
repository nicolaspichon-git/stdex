Stdex Library {#mainpage}
=============

# Introduction

**Stdex** is a header-only C++ library providing post-C++14 features for C++14 compilers. 

The missing features could be components or language features.
Missing components could be provided by C++14 experimental STL libraries, or **Boost** libraries, or even less known libraries like **Eggs**..
The library also provides a few macros or non-standard components for missing language features.

# Motivation
- You need C++17 or C++20 features like `std::string_view`, `std::in_place` or `std::as_const`.
- But your company is still stuck with C++14 and you have no idea when it has planned to upgrade your compiler. 

# Rationale
- Can compile with C++14 standards or _latter_.
- Use C++xx components whith C++xx compilers when possible.
- Otherwise use C++14 experimental STL libraries when possible.
- Otherwise use and adapt **Boost** libraries when possible.
- Otherwise use hand-crafted components.
- Wrapp all the missing features in the single `stdex` namespace.
- At long-term, STL components should still compile with post-C++14 compilers when the `stdex` namespace name is replaced with `std`.

# Reference
- Standard features (since c++17, C++20, or C++23):
    - Language features:
        * `XXX_CONSTEXPR` macros
    - STL components:
        * utility:
            * `stdex::as_const`
            * `stdex::in_place_t`
            * `stdex::in_place_type_t`
        * type_traits:
            * `stdex::void_t`
            * `stdex::make_type` (may use **Boost.Utility**) 
            * static logical operations:
                * `stdex::negation`
                * `stdex::conjunction`
                * `stdex::disjunction`
        * string_view:
            * `stdex::string_view` (may use **Boost.Utility**)
        * any:
            * `stdex::any` (may use `boost::any` (from **Boost.Any** library in **Boost** &ge; ???))
        * variant:
            * `stdex::variant` (may use `boost::variant2` (from **Boost.Variant2** library in **Boost** &ge; 1.72))
        * optional:
            * `stdex::optional` (use `boost::optional` until c++17 (from **Boost** library &ge; ???)
        * functional:
        * `stdex::invoke` (use `eggs::invoke` until c++17 (from **Eggs.Invoke** library))
- Experimental features (still not available in standard):
    * memory:
        * `stdex::observer_ptr`
- Non-standard features:
    - `stdex::static_constexpr`
    - `stdex::null_deleter`
