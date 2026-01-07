//------------------------------------------------------------------------------
//
// Copyright (c) 2020 Nicolas Pichon
//
// Distributed under the Boost Software License, Version 1.0.
//    (See http://www.boost.org/LICENSE_1_0.txt)
//
//------------------------------------------------------------------------------

#include "dataset/static_constexpr_dataset_testsuite.h"
#include <stdex/static_constexpr.hpp>
#include <stdex/testing/printing/resettable_ostringstream.hpp>
#include <boost/test/unit_test.hpp>

////////////////////////////////////////////////////////////////////////////////
namespace stdex { namespace tests {
////////////////////////////////////////////////////////////////////////////////

using namespace StdexStaticConstexprDataset;

namespace
{
    static stdex::testing::resettable_ostringstream testout;// local to the current translation unit
}

BOOST_AUTO_TEST_SUITE( StdexStaticConstexprBoostTestSuite )

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
