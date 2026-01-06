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
#   include <any>
#else
//  until c++14:
#   include <boost/any.hpp>
#endif

namespace stdex
{
#if defined(STDEX_USE_STDNS)
    /// @ingroup stdex_any
    /// @brief The STL's @c std::any type.
    using std::any;

    /// @ingroup stdex_any
    /// @brief The STL's @c std::any_cast function.
    using std::any_cast;

    /// @ingroup stdex_any
    /// @brief The STL's @c std::bad_any_cast exception type.
    using std::bad_any_cast;

    /// @ingroup stdex_any
    bool has_value(any const &a) noexcept
    {
        return a.has_value();
    }

    /// @ingroup stdex_any
    void reset(any &a)
    {
        a.reset();
    }
#else
    /// @ingroup stdex_any
    /// @brief An STL's @c any replacement (waiting for c++17).
    using boost::any;

    /// @ingroup stdex_any
    /// @brief An STL's @c any_cast replacement (waiting for c++17).
    using boost::any_cast;

    /// @ingroup stdex_any
    /// @brief An STL's @c bad_any_cast replacement (waiting for c++17).
    using boost::bad_any_cast;

    /// @ingroup stdex_any
    bool has_value(any const &a) noexcept
    {
        return !a.empty();
    }

    /// @ingroup stdex_any
    void reset(any &a)
    {
        a.clear();
    }
#endif
}

#if defined(STDEX_USE_STDNS)
#undef STDEX_USE_STDNS
#endif
