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
#else
//  until c++14 :
#   include <boost/type_traits/is_nothrow_swappable.hpp>
#endif

namespace stdex
{
#if defined(STDEX_USE_STDNS)

    /// @ingroup stdex_swappable
    /// @brief The standard @c std::is_nothrow_swappable .
    using std::is_nothrow_swappable;

#else

    /// @ingroup stdex_swappable
    /// @brief A @c std::is_nothrow_swappable replacement (waiting for c++17).
    using boost::is_nothrow_swappable;

#endif
}

#if defined(STDEX_USE_STDNS)
#undef STDEX_USE_STDNS
#endif
