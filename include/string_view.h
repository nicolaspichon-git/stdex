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
#   include <string_view>
#else
//  until c++14 :
#   include <boost/utility/string_view.hpp>
#endif

#include <string>

namespace stdex
{
#if defined(STDEX_USE_STDNS)

    /// @ingroup stdex_stringview
    /// @brief The standard @c std::string_view .
    using std::string_view;

    /// @ingroup stdex_stringview
    /// @note A non-standard helper (ensure compatibility with C++14 replacement).
    inline std::string to_string(string_view const &sv) { return std::string(sv); }

#else

    /// @ingroup stdex_stringview
    /// @brief A @c std::string_view replacement (waiting for c++17).
    using boost::string_view;

    /// @ingroup stdex_stringview
    /// @note A non-standard conversion helper (standard @c std::sring_view does not have the @c to_string method)
    inline std::string to_string(string_view const &sv) { return sv.to_string(); }

#endif
}

#if defined(STDEX_USE_STDNS)
#undef STDEX_USE_STDNS
#endif
