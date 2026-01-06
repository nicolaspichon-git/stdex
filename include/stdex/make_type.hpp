//------------------------------------------------------------------------------
//
// Copyright (c) 2021 Nicolas Pichon
//
// Distributed under the Boost Software License, Version 1.0.
//    (See http://www.boost.org/LICENSE_1_0.txt)
//
//------------------------------------------------------------------------------
#pragma once

namespace stdex
{
    /// @ingroup stdex_nonstandard
    template < typename T >
    struct make_type { using type = T; };
}
