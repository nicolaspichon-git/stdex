//------------------------------------------------------------------------------
//
// Copyright (c) 2021 Nicolas Pichon
//
// Distributed under the Boost Software License, Version 1.0.
//    (See http://www.boost.org/LICENSE_1_0.txt)
//
//------------------------------------------------------------------------------
#pragma once

#include <stdex/static_constexpr.h>

namespace stdex
{
    /// @ingroup stdex_nonstandard
    template < typename T >
    struct null_deleter_t
    {
        explicit null_deleter_t() = default;
        void operator()(T*) const noexcept {};
    };

    namespace
    {
        /// @ingroup stdex_nonstandard
        template < typename T >
        constexpr auto &null_deleter = stdex::static_constexpr<null_deleter_t<T>>::value;
    }
}
