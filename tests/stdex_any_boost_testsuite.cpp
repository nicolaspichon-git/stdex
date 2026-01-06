//------------------------------------------------------------------------------
//
// Copyright (c) 2020 Nicolas Pichon
//
// Distributed under the Boost Software License, Version 1.0.
//    (See http://www.boost.org/LICENSE_1_0.txt)
//
//------------------------------------------------------------------------------
#include <boost/test/unit_test.hpp>

#include <stdex/any.hpp>

////////////////////////////////////////////////////////////////////////////////
namespace stdex { namespace tests {
////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE( StdexAnyBoostTestSuite )

BOOST_AUTO_TEST_CASE( AnyTypeTest )
{
    const auto expected_value_1 = 1;
    stdex::any a = expected_value_1;
    BOOST_TEST(a.type().name() == typeid(expected_value_1).name());
    BOOST_TEST(stdex::any_cast<decltype(expected_value_1)>(a) == expected_value_1);

    const auto expected_value_2 = 3.14;
    a = expected_value_2;
    BOOST_TEST(a.type().name() ==  typeid(expected_value_2).name());
    BOOST_TEST(stdex::any_cast<decltype(expected_value_2)>(a) == expected_value_2);

    const auto expected_value_3 = true;
    a = expected_value_3;
    BOOST_TEST(a.type().name() == typeid(expected_value_3).name());
    BOOST_TEST(stdex::any_cast<decltype(expected_value_3)>(a) == expected_value_3);
}

BOOST_AUTO_TEST_CASE( BadCastTest )
{
    try
    {
        stdex::any a = 1;
        stdex::any_cast<float>(a);
        BOOST_TEST((false));
    }
    catch (const stdex::bad_any_cast&)
    {
        BOOST_TEST((true));
    }
    catch(...)
    {
        BOOST_TEST((false));
    }
}

BOOST_AUTO_TEST_CASE( HasValueTest )
{
    stdex::any a = 2;
    BOOST_TEST(stdex::has_value(a) == true);

    // reset
    stdex::reset(a);
    BOOST_TEST(stdex::has_value(a) == false);
}

BOOST_AUTO_TEST_CASE( PointerToContainedDataTest )
{
    // pointer to contained data
    stdex::any a = 3;
    int* i = stdex::any_cast<int>(&a);
    BOOST_TEST(*i == 3);
}

BOOST_AUTO_TEST_SUITE_END()

////////////////////////////////////////////////////////////////////////////////
}}// EONS stdex::tests
////////////////////////////////////////////////////////////////////////////////
