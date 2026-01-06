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
#   include <utility>
#else
//  until c++14:
#   include <type_traits>
#endif

namespace stdex
{
#if defined(STDEX_USE_STDNS)
    /// @ingroup stdex_utility
    using std::as_const;
#else
    /// @ingroup stdex_utility
    /// @brief Forms lvalue reference to const type of x.
    /// @see https://en.cppreference.com/w/cpp/utility/as_const
    ///
    /// Usage:
    ///
    /// @code
    /// #include <cassert>
    /// #include <string>
    /// #include <type_traits>
    /// #include <utility>
    ///
    /// int main()
    /// {
    ///     std::string mutableString = "Hello World!";
    ///     auto&& constRef = std::as_const(mutableString);
    ///
    ///     mutableString.clear(); // OK
    ///     //  constRef.clear(); // Error: 'constRef' is 'const' qualified,
    ///     //        but 'clear' is not marked const
    ///
    ///     assert(&constRef == &mutableString);
    ///     assert(&std::as_const(mutableString) == &mutableString);
    ///
    ///     using ExprType = std::remove_reference_t<decltype(std::as_const(mutableString))>;
    ///
    ///     static_assert(std::is_same_v<std::remove_const_t<ExprType>, std::string>,
    ///                   "ExprType should be some kind of string.");
    ///     static_assert(!std::is_same_v<ExprType, std::string>,
    ///                   "ExprType shouldn't be a mutable string.");
    /// }
    /// @endcode
    template < typename T >
    inline constexpr std::add_const_t<T> &as_const(T &x) noexcept
    {
        return x;
    }

    /// @ingroup stdex_utility
    /// @brief const rvalue reference overload is deleted to disallow rvalue arguments.
    /// @see https://en.cppreference.com/w/cpp/utility/as_const
    template < typename T >
    void as_const(const T&&) = delete;
#endif
}

#if defined(STDEX_USE_STDNS)
#undef STDEX_USE_STDNS
#endif

