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
#   include <optional>
#else
//  until c++14 :
#   include <boost/optional.hpp>
// TODO :
//#   include <stdex/static_constexpr.h>
#endif

namespace stdex
{
#if defined(STDEX_USE_STDNS)

    /// @ingroup stdex_optional
    /// @brief The standard @c std::optional .
    using std::optional;

    /// @ingroup stdex_optional
    using std::nullopt_t;

// TODO :
//    /// @ingroup stdex_optional
//    using std::nullopt;

#else

    /// @ingroup stdex_optional
    /// @brief A STL's @c optional replacement (waiting for c++17).
    using boost::optional;

    /// @ingroup stdex_optional
    using nullopt_t = boost::none_t;

// DONT COMPILE :
//    namespace
//    {
//        /// @ingroup stdex_optional
//        constexpr const bool &nullopt = stdex::static_constexpr<nullopt_t>::value;
//    }

#endif
}

#if defined(STDEX_USE_STDNS)
#undef STDEX_USE_STDNS
#endif
