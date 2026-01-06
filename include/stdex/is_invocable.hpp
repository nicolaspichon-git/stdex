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
#   include <functional>
#else
//  until c++14 :
#   include <eggs/invoke.hpp>
#endif

namespace stdex
{
#if defined(STDEX_USE_STDNS)

    /// @ingroup stdex_invocable
    /// @brief The standard @c std::is_invocable .
    using std::is_invocable;

    /// @ingroup stdex_invocable
    /// @brief The standard @c std::is_invocable_r .
    using std::is_invocable_t;

#else

    /// @ingroup stdex_invocable
    /// @brief A @c std::is_invocable replacement (waiting for c++17).
    using eggs::is_invocable;

    /// @ingroup stdex_invocable
    /// @brief A @c std::is_invocable_r replacement (waiting for c++17).
    using eggs::is_invocable_r;

#endif
}

#if defined(STDEX_USE_STDNS)
#undef STDEX_USE_STDNS
#endif
