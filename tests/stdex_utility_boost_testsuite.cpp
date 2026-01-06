//------------------------------------------------------------------------------
//
// Copyright (c) 2020 Nicolas Pichon
//
// Distributed under the Boost Software License, Version 1.0.
//    (See http://www.boost.org/LICENSE_1_0.txt)
//
//------------------------------------------------------------------------------
#include <boost/test/unit_test.hpp>

#include <stdex/as_const.hpp>

////////////////////////////////////////////////////////////////////////////////
namespace stdex { namespace tests {
////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE( StdexUtilityBoostTestSuite )

BOOST_AUTO_TEST_CASE( AsConstUsageTest )
{
    std::string mutableString = "Hello World!";
    auto&& constRef = stdex::as_const(mutableString);

    mutableString.clear(); // OK
    //  constRef.clear(); // Error: 'constRef' is 'const' qualified,
    //        but 'clear' is not marked const

    BOOST_TEST(&constRef == &mutableString);
    BOOST_TEST(&stdex::as_const(mutableString) == &mutableString);

    using ExprType = std::remove_reference_t<decltype(stdex::as_const(mutableString))>;

    static_assert(std::is_same<std::remove_const_t<ExprType>, std::string>::value, "ExprType should be some kind of string.");
    static_assert(!std::is_same<ExprType, std::string>::value, "ExprType shouldn't be a mutable string.");
}

BOOST_AUTO_TEST_SUITE_END()

////////////////////////////////////////////////////////////////////////////////
}}// EONS stdex::tests
////////////////////////////////////////////////////////////////////////////////
