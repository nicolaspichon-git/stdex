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
#   include <boost/core/ignore_unused.hpp>
#endif

namespace stdex
{
#if defined(STDEX_USE_STDNS)
    /// @ingroup stdex_utility
    using std::in_place_t;
    /// @ingroup stdex_utility
    using std::in_place;
#else

    /// @ingroup stdex_utility
    struct in_place_t
    {
        explicit in_place_t() = default;
    };

    namespace
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
        /// @ingroup stdex_utility
        constexpr auto &in_place = stdex::static_constexpr<in_place_t>::value;
#pragma GCC diagnostic pop
    }

#endif
}

#if defined(STDEX_USE_STDNS)
#undef STDEX_USE_STDNS
#endif
