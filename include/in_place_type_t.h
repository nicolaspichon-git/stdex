//------------------------------------------------------------------------------
//
// Copyright (c) 2021 Nicolas Pichon
//
// Distributed under the Boost Software License, Version 1.0.
//    (See http://www.boost.org/LICENSE_1_0.txt)
//
//------------------------------------------------------------------------------
#pragma once

#include <stdex/stdex_config.h>

#if defined(STDEX_USE_STDNS)
#undef STDEX_USE_STDNS
#endif

#if defined(STDEX_SINCE_CXX17)
#   define STDEX_USE_STDNS
#   include <utility>
#else
//  until c++14 :
#   include <stdex/static_constexpr.h>
#endif

namespace stdex
{
#if defined(STDEX_USE_STDNS)
    /// @ingroup stdex_utility
    using std::in_place_type_t;
    /// @ingroup stdex_utility
    using std::in_place_type;
#else

    /// @ingroup stdex_utility
    template < typename T >
    struct in_place_type_t
    {
        explicit in_place_type_t() = default;
    };

    namespace
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
        /// @ingroup stdex_utility
        template < typename T >
        constexpr auto &in_place_type = stdex::static_constexpr<in_place_type_t<T>>::value;
#pragma GCC diagnostic pop
    }

#endif
}

#if defined(STDEX_USE_STDNS)
#undef STDEX_USE_STDNS
#endif
