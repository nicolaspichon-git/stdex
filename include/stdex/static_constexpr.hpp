    //------------------------------------------------------------------------------
//
// Copyright (c) 2021 Nicolas Pichon
//
// Distributed under the Boost Software License, Version 1.0.
//    (See http://www.boost.org/LICENSE_1_0.txt)
//
//------------------------------------------------------------------------------
#pragma once

#include <stdex/stdex_config.hpp>

#if defined(STDEX_USE_INLINED_STATIC_CONSTEXPR)
#undef STDEX_USE_INLINED_STATIC_CONSTEXPR
#endif

#if defined(STDEX_SINCE_CXX17)
#   define STDEX_USE_INLINED_STATIC_CONSTEXPR
#endif

namespace stdex
{
    /// @ingroup stdex_nonstandard
    /// @brief Build an header-defined constant global object at compile-time.
    /// @pre T must have a constexpr default constructor (implicitly or explicitly).
    ///
    /// This is an Eric Niebler's technic for Range3. It avoids the ODR (One Definition Rule)
    /// violation despite the global object is header-defined. The point is to declare
    /// the object as static constexpr.
    ///
    /// Usage:
    ///
    /// @code
    ///      #include <stdex/static_constexpr.h>
    ///      namespace
    ///      {
    ///          const auto &my_global_object = static_constexpr<my_object_type>::value;
    ///      }
    /// @endcode
    template < typename T >
    struct static_constexpr
    {
        // note :
        //  from cppreference :
        //      a constexpr specifier used in an object declaration or non-static member function (until C++14) implies const.
        //      a constexpr specifier used in a function or static member variable (since C++17) declaration implies inline.

#if defined(STDEX_USE_INLINED_STATIC_CONSTEXPR)
        inline static constexpr T value{};
#else
        static constexpr T value{};
#endif
    };

#if !defined(STDEX_USE_INLINED_STATIC_CONSTEXPR)
    /// @ingroup stdex_nonstandard
    template < typename T > constexpr T static_constexpr<T>::value;
#endif
}

#if defined(STDEX_USE_INLINED_STATIC_CONSTEXPR)
#undef STDEX_USE_INLINED_STATIC_CONSTEXPR
#endif
