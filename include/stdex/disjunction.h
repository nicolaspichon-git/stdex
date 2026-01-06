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
#   include <type_traits>
#else
//  until c++14 :
#   include <stdex/conjunction.h>
#   include <stdex/negation.h>
#endif


namespace stdex
{
#if defined(STDEX_USE_STDNS)

    /// @ingroup stdex_typetraits
    using std::disjunction;

    /// @ingroup stdex_typetraits
    using std::disjunction_v;

#else

    /// @ingroup stdex_typetraits
    /// @brief @c std::true_type if @c Bs... is not empty and at least one @c Bs::value is true.
    template < typename... Bs >
    struct disjunction : public negation< conjunction< negation<Bs>... > >
    {};

    namespace
    {
        /// @ingroup stdex_typetraits
        template < typename... Bs >
        constexpr const bool &disjunction_v = (stdex::static_constexpr<disjunction<Bs...>>::value).value;
    }

#endif
}

#if defined(STDEX_USE_STDNS)
#undef STDEX_USE_STDNS
#endif
