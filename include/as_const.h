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
//  until c++14:
#   include <type_traits>
#endif

namespace stdex
{
#if defined(STDEX_USE_STDNS)
    /// @ingroup stdex_utility
    using std::as_const;
#else

    /// @ingroup stdex_utility
    /// @brief Forms lvalue reference to const type of x.
    /// @see https://en.cppreference.com/w/cpp/utility/as_const
    template < typename T >
    inline constexpr std::add_const_t<T> &as_const(T &x) noexcept
    {
        return x;
    }

    /// @ingroup stdex_utility
    /// @brief const rvalue reference overload is deleted to disallow rvalue arguments.
    /// @see https://en.cppreference.com/w/cpp/utility/as_const
    template < typename T >
    void as_const(const T&&) = delete;

#endif
}

#if defined(STDEX_USE_STDNS)
#undef STDEX_USE_STDNS
#endif

