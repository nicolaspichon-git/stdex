//------------------------------------------------------------------------------
//
// Copyright (c) 2020 Nicolas Pichon
//
// Distributed under the Boost Software License, Version 1.0.
//    (See http://www.boost.org/LICENSE_1_0.txt)
//
//------------------------------------------------------------------------------
#pragma once

#include <boost/core/demangle.hpp>
#include <typeindex>
#include <ostream>

////////////////////////////////////////////////////////////////////////////////
namespace solo { namespace testing {
////////////////////////////////////////////////////////////////////////////////

/// @ingroup SoloCoreTesting
/// @brief Ready-to-use <c>std::type_info</c> outputter for <c>std::ostream</c>.
inline ::std::ostream &operator<<(::std::ostream &os, ::std::type_info const &ti)
{
    os << ::boost::core::demangle(ti.name());
    return os;
}

/// @ingroup SoloCoreTesting
/// @brief Ready-to-use <c>std::type_index</c> outputter for <c>std::ostream</c>.
inline ::std::ostream &operator<<(::std::ostream &os, ::std::type_index const &ti)
{
    os << ::boost::core::demangle(ti.name());
    return os;
}

////////////////////////////////////////////////////////////////////////////////
}}// EONS SOLO::TESTING
////////////////////////////////////////////////////////////////////////////////
