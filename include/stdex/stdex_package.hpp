//------------------------------------------------------------------------------
//
// Copyright (c) 2020 Nicolas Pichon
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//------------------------------------------------------------------------------
#pragma once

/// @defgroup stdex Stdex Library
/// @ingroup SoloCore
/// @brief C++14 missing and non-standard features

/// @defgroup stdex_utility C++14 missing utility components
/// @ingroup stdex

/// @defgroup stdex_typetraits C++14 missing type traits
/// @ingroup stdex

/// @defgroup stdex_any C++14 missing any components
/// @ingroup stdex

/// @defgroup stdex_variant C++14 missing variant components
/// @ingroup stdex

/// @defgroup stdex_optional C++14 missing optional components
/// @ingroup stdex

/// @defgroup stdex_stringview C++14 missing string view components
/// @ingroup stdex

/// @defgroup stdex_swappable C++14 missing swappable components
/// @ingroup stdex

/// @defgroup stdex_invocable C++14 missing invocable components
/// @ingroup stdex

/// @defgroup stdex_experimental Some STL experimental components
/// @ingroup stdex

/// @defgroup stdex_nonstandard Some STL-like non-standard components
/// @ingroup stdex

//..............................................................................

// utility:
#include <stdex/as_const.hpp>
#include <stdex/in_place_t.hpp>
#include <stdex/in_place_type_t.hpp>

// type traits:
#include <stdex/void_t.hpp>
#include <stdex/negation.hpp>
#include <stdex/conjunction.hpp>
#include <stdex/disjunction.hpp>

// any:
#include <stdex/any.hpp>

// variant:
#include <stdex/variant.hpp>

// optional:
#include <stdex/optional.hpp>

// string view:
#include <stdex/string_view.hpp>

// swappable:
#include <stdex/is_nothrow_invocable.hpp>

// invocable:
#include <stdex/is_invocable.hpp>
#include <stdex/is_nothrow_invocable.hpp>
#include <stdex/invoke_result.hpp>
#include <stdex/invoke.hpp>

// stl features:
#include <stdex/cpp_lib_constexpr.hpp>

// experimental:
#include <stdex/observer_ptr.hpp>

// extensions:
#include <stdex/static_constexpr.hpp>
#include <stdex/null_deleter.hpp>
#include <stdex/make_type.hpp>

////////////////////////////////////////////////////////////////////////////////
