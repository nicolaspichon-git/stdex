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
#   // until c++14 :
#   include <stdex/static_constexpr.hpp>
#   include <type_traits>
#endif


namespace stdex
{
#if defined(STDEX_USE_STDNS)

    /// @ingroup stdex_typetraits
    using std::negation;

    /// @ingroup stdex_typetraits
    using std::negation_v;

#else

    /// @ingroup stdex_typetraits
    template < typename B >
    struct negation
            : std::integral_constant<bool,!bool(B::value)>
    {};

    namespace
    {
        /// @ingroup stdex_typetraits
        template < typename B >
        constexpr const bool &negation_v = (stdex::static_constexpr<negation<B>>::value).value;
    }

#endif
}

#if defined(STDEX_USE_STDNS)
#undef STDEX_USE_STDNS
#endif
