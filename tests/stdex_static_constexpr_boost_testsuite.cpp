//------------------------------------------------------------------------------
//
// Copyright (c) 2020 Nicolas Pichon
//
// Distributed under the Boost Software License, Version 1.0.
//    (See http://www.boost.org/LICENSE_1_0.txt)
//
//------------------------------------------------------------------------------
#include <boost/test/unit_test.hpp>

#include <stdex/static_constexpr.h>

#include "dataset/static_constexpr_dataset_testsuite.h"
#include "helpers/testing_ostream.h"

////////////////////////////////////////////////////////////////////////////////
namespace stdex { namespace tests {
////////////////////////////////////////////////////////////////////////////////

using namespace StdexStaticConstexprDataset;

namespace
{
    static helpers::testing_ostream testout;// local to the current translation unit
}

BOOST_AUTO_TEST_SUITE( StdexStaticConstexprTestSuite )

BOOST_AUTO_TEST_CASE( PreliminaryTest )
{
    using stdex::static_constexpr;

    constexpr const auto &gn = static_constexpr<int>::value;
    testout.reset();
    testout << gn;
    BOOST_TEST(testout.str() == "0");
    constexpr auto &gn2 = static_constexpr<int>::value;
    BOOST_TEST(gn2 == gn);
    // should not compile (gn is const) : gn2 = 1;
    auto n3 = static_constexpr<int>::value;
    BOOST_TEST(n3 == gn);
    n3 = 1;

    constexpr auto &ga = static_constexpr<TestObjectA>::value;// mutable but constexpr reference
    testout.reset();
    testout << ga.data();
    BOOST_TEST(testout.str() == "1");

    // should not compile (as constexpr, ga is const) : ga.setdata(2);
    //testout.reset();
    //testout << ga.data();
    //BOOST_TEST(testout.str() == "2");

    //auto &ga2 = stdex::static_constexpr<TestObjectA>::value;// mutable reference
    // should not compile (as constexpr, ga is still const...) : ga2.setdata(2);
    //testout.reset();
    //testout << ga.data();
    //BOOST_TEST(testout.str() == "2");

    auto ga_id = GetGlobalTestObjectA_Identifier();
    BOOST_TEST(ga.id() == ga_id);
}

BOOST_AUTO_TEST_SUITE_END()

////////////////////////////////////////////////////////////////////////////////
}}// EONS stdex::tests
////////////////////////////////////////////////////////////////////////////////
