//------------------------------------------------------------------------------
//
// Copyright (c) 2021 Nicolas Pichon
//
// Distributed under the Boost Software License, Version 1.0.
//    (See http://www.boost.org/LICENSE_1_0.txt)
//
//------------------------------------------------------------------------------
#pragma once

#if defined(STDEX_SINCE_CXX11)
#undef STDEX_SINCE_CXX11
#endif

#if defined(STDEX_UNTIL_CXX11)
#undef STDEX_UNTIL_CXX11
#endif

#if defined(STDEX_SINCE_CXX14)
#undef STDEX_SINCE_CXX14
#endif

#if defined(STDEX_UNTIL_CXX14)
#undef STDEX_UNTIL_CXX14
#endif

#if defined(STDEX_SINCE_CXX17)
#undef STDEX_SINCE_CXX17
#endif

#if defined(STDEX_UNTIL_CXX17)
#undef STDEX_UNTIL_CXX17
#endif

#if defined(STDEX_SINCE_CXX20)
#undef STDEX_SINCE_CXX20
#endif

#if defined(STDEX_UNTIL_CXX20)
#undef STDEX_UNTIL_CXX20
#endif

#if defined(STDEX_SINCE_CXX23)
#undef STDEX_SINCE_CXX23
#endif

//..............................................................................

#if __cplusplus >= 201103L
#   define STDEX_SINCE_CXX11
#else
#   define STDEX_UNTIL_CXX11
#endif

#if __cplusplus >= 201402L
#   define STDEX_SINCE_CXX14
#else
#   define STDEX_UNTIL_CXX14
#endif

#if __cplusplus >= 201703L
#   define STDEX_SINCE_CXX17
#else
#   define STDEX_UNTIL_CXX17
#endif

#if __cplusplus >= 202002L
#   define STDEX_SINCE_CXX20
#else
#   define STDEX_UNTIL_CXX20
#endif

#if __cplusplus >= 202302L
#   define STDEX_SINCE_CXX23
#endif

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
