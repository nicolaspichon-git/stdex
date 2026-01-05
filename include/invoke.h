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
#   include <functional>
#else
//  until c++14 :
#   include <eggs/invoke.hpp>
#endif

namespace stdex
{
#if defined(STDEX_USE_STDNS)

    /// @ingroup stdex_invocable
    /// @brief The standard @c std::invoke .
    using std::invoke;

    /// @ingroup stdex_invocable
    /// @brief The standard @c std::invoke_r .
    using std::invoke_r;

#else

    /// @ingroup stdex_invocable
    /// @brief A @c std::invoke replacement (waiting for c++17).
    using eggs::invoke;

    /// @ingroup stdex_invocable
    /// @brief A @c std::invoke_r replacement (waiting for c++17).
    using eggs::invoke_r;

#endif
}

#if defined(STDEX_USE_STDNS)
#undef STDEX_USE_STDNS
#endif
