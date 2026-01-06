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
#   include <variant>
#else
//  until c++14 :
#   include <boost/variant2/variant.hpp>
#endif

namespace stdex
{
#if defined(STDEX_USE_STDNS)

    /// @ingroup stdex_variant
    /// @brief The standard @c std::optional .
    using std::variant;

    /// @ingroup stdex_variant
    using std::monostate;

    /// @ingroup stdex_variant
    using std::get;

    /// @ingroup stdex_variant
    using std::get_if;

    /// @ingroup stdex_variant
    using std::visit;

    /// @ingroup stdex_variant
    using std::holds_alternative;

//    /// @ingroup stdex_variant
//    /// @note A non-standard result of visitation function helper
//    /// (the actual result of @c std::visit invocation depends on whether the arguments are variant or variant-based).
//    template < typename Visitor, typename... Variants >
//    using visitation_function_result_type = ???;

#else

    /// @ingroup stdex_variant
    /// @brief A STL's @c variant replacement (waiting for c++17).
    using boost::variant2::variant;

    /// @ingroup stdex_variant
    using boost::variant2::monostate;

    /// @ingroup stdex_variant
    using boost::variant2::get;

    /// @ingroup stdex_variant
    using boost::variant2::get_if;

    /// @ingroup stdex_variant
    using boost::variant2::visit;

    /// @ingroup stdex_variant
    using boost::variant2::holds_alternative;

//    /// @ingroup stdex_variant
//    /// @note A non-standard result of visitation function helper
//    /// (the actual result of @c std::visit invocation depends on whether the arguments are variant or variant-based).
//    template < typename Visitor, typename... Variants >
//    using visitation_function_result_type = boost::variant2::detail::Vret<Visitor,Variants...>;

#endif
}

#if defined(STDEX_USE_STDNS)
#undef STDEX_USE_STDNS
#endif
