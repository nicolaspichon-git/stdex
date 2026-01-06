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
#   include <stdex/static_constexpr.hpp>
#   include <type_traits>
#endif


namespace stdex
{
#if defined(STDEX_USE_STDNS)

    /// @ingroup stdex_typetraits
    using std::conjunction;

    /// @ingroup stdex_typetraits
    using std::conjunction_v;

#else

    namespace detail
    {
        template < bool... >
        struct bpack {};

        template < bool... Bs >
        using bconj = std::is_same< bpack<true,Bs...>, bpack<Bs...,true> >;
    }

    /// @ingroup stdex_typetraits
    /// @brief @c std::true_type if all @c Bs::value are true (or @c Bs... is empty).
    /// @note Do not conform exactly STL requirements (all @c Bs::value are instanciated).
    /// @see https://en.cppreference.com/w/cpp/types/conjunction
    template < typename... Bs >
    struct conjunction : public detail::bconj<bool(Bs::value)...>
    {};

    namespace
    {
        /// @ingroup stdex_typetraits
        /// @brief Helper variable template.
        template < typename... Bs >
        constexpr const bool &conjunction_v = (stdex::static_constexpr<conjunction<Bs...>>::value).value;
    }

#endif
}

#if defined(STDEX_USE_STDNS)
#undef STDEX_USE_STDNS
#endif
