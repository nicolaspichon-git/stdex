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

#if defined(STDEX_USE_STDNS)
#undef STDEX_USE_STDNS
#endif

#if defined(STDEX_SINCE_CXX17)
#   define STDEX_USE_STDNS
#   include <type_traits>
#endif

namespace stdex
{
    // -- stdex::void_t

#if defined(STDEX_USE_STDNS)
    /// @ingroup stdex_typetraits
    using std::void_t;
#else
#   if defined(STDEX_UNTIL_CXX11)

    // until CWG 1558 (a C++11 defect), unused parameters in alias templates were not guaranteed to ensure SFINAE and could be ignored,
    // so earlier compilers require a more complex definition of void_t, such as

    namespace detail
    {
        template < typename... >
        struct make_void { typedef void type; };
    }

    /// @ingroup stdex_typetraits
    /// @brief The STL's @ void_t transformation (since c++17).
    template < typename... Ts >
    using void_t = typename detail::make_void<Ts...>::type;

#   else

    /// @ingroup stdex_typetraits
    /// @brief The STL's @ void_t transformation (since c++17).
    template < typename... >
    using void_t = void;

#   endif
#endif
}

#if defined(STDEX_USE_STDNS)
#undef STDEX_USE_STDNS
#endif

#if defined(STDEX_USE_PRECXX14)
#undef STDEX_USE_PRECXX14
#endif
