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

// utility :
#include <stdex/as_const.h>
#include <stdex/in_place_t.h>
#include <stdex/in_place_type_t.h>

// type traits :
#include <stdex/void_t.h>
#include <stdex/negation.h>
#include <stdex/conjunction.h>
#include <stdex/disjunction.h>

// optional :
#include <stdex/optional.h>

// variant :
#include <stdex/variant.h>

// string view :
#include <stdex/string_view.h>

// swappable :
#include <stdex/is_nothrow_invocable.h>

// invocable :
#include <stdex/is_invocable.h>
#include <stdex/is_nothrow_invocable.h>
#include <stdex/invoke_result.h>
#include <stdex/invoke.h>

// stl features :
#include <stdex/cpp_lib_constexpr.h>

// experimental :
#include <stdex/observer_ptr.h>

// extensions :
#include <stdex/static_constexpr.h>
#include <stdex/null_deleter.h>
#include <stdex/make_type.h>

////////////////////////////////////////////////////////////////////////////////
