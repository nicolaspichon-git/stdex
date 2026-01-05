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

#if defined(STDEX_STD_STRING_CONSTEXPR)
#undef STDEX_STD_STRING_CONSTEXPR
#endif

#if defined(STDEX_STD_FIND_CONSTEXPR)
#undef STDEX_STD_FIND_CONSTEXPR
#endif

#if defined(STDEX_STD_CONTAINER_CONSTEXPR)
#undef STDEX_STD_CONTAINER_CONSTEXPR
#endif

//..............................................................................

#if defined(STDEX_SINCE_CXX20)
#   define STDEX_STD_STRING_CONSTEXPR constexpr
#   define STDEX_STD_FIND_CONSTEXPR constexpr
#   define STDEX_STD_CONTAINER_CONSTEXPR constexpr
#else
#   define STDEX_STD_STRING_CONSTEXPR
#   define STDEX_STD_FIND_CONSTEXPR
#   define STDEX_STD_CONTAINER_CONSTEXPR
#endif

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
