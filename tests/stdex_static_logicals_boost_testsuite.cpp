//------------------------------------------------------------------------------
//
// Copyright (c) 2020 Nicolas Pichon
//
// Distributed under the Boost Software License, Version 1.0.
//    (See http://www.boost.org/LICENSE_1_0.txt)
//
//------------------------------------------------------------------------------
#include <boost/test/unit_test.hpp>

#include <stdex/conjunction.h>
#include <stdex/disjunction.h>
#include <stdex/negation.h>
#include <stdex/static_constexpr.h>

#include "helpers/testing_ostream.h"

////////////////////////////////////////////////////////////////////////////////
namespace SoloTests {
////////////////////////////////////////////////////////////////////////////////

namespace
{
    static ::solo::testing::testing_ostream testout;// local to the current translation unit
}

BOOST_AUTO_TEST_SUITE( StdexStaticLogicalsTestSuite )

BOOST_AUTO_TEST_CASE( PreliminaryTest )
{
    using stdex::conjunction;
    using stdex::disjunction;
    using stdex::negation;

    {
        // -- conjunction :

        static_assert( std::is_base_of< std::true_type, stdex::conjunction<> >::value, "");
        static_assert( stdex::conjunction<>::value == true, "");

        static_assert( stdex::conjunction<std::true_type>::value == true, "");
        static_assert( stdex::conjunction<std::false_type>::value == false, "");

        static_assert( stdex::conjunction<std::true_type,std::true_type>::value == true, "");
        static_assert( stdex::conjunction<std::true_type,std::false_type>::value == false, "");
        static_assert( stdex::conjunction<std::false_type,std::true_type>::value == false, "");
        static_assert( stdex::conjunction<std::false_type,std::false_type>::value == false, "");

        static_assert( stdex::conjunction<std::true_type,std::true_type,std::true_type>::value == true, "");
        static_assert( stdex::conjunction<std::true_type,std::true_type,std::false_type>::value == false, "");
        static_assert( stdex::conjunction<std::true_type,std::false_type,std::true_type>::value == false, "");
        static_assert( stdex::conjunction<std::false_type,std::true_type,std::true_type>::value == false, "");
        static_assert( stdex::conjunction<std::true_type,std::false_type,std::false_type>::value == false, "");
        static_assert( stdex::conjunction<std::false_type,std::true_type,std::false_type>::value == false, "");
        static_assert( stdex::conjunction<std::false_type,std::false_type,std::true_type>::value == false, "");
        static_assert( stdex::conjunction<std::false_type,std::false_type,std::false_type>::value == false, "");

        constexpr auto &conjunction_instance = stdex::static_constexpr< conjunction<std::true_type> >::value;
        static_assert( std::is_same< decltype(conjunction_instance), const conjunction<std::true_type>& >::value, "");
        constexpr auto &conjunction_instance_v = conjunction_instance.value;
        static_assert( std::is_same< decltype(conjunction_instance_v), const bool& >::value, "");

        static_assert( stdex::conjunction_v<std::true_type> == true, "");
        static_assert( stdex::conjunction_v<std::false_type> == false, "");

        // -- negation :

        // should not compile : negation of the empty set is not defined
        //static_assert( stdex::negation<>::value, "");

        static_assert( stdex::negation<std::true_type>::value == false, "");
        static_assert( stdex::negation<std::false_type>::value == true, "");

        constexpr auto &negation_instance = stdex::static_constexpr< negation<std::true_type> >::value;
        static_assert( std::is_same< decltype(negation_instance), const negation<std::true_type>& >::value, "");
        constexpr auto &negation_instance_v = negation_instance.value;
        static_assert( std::is_same< decltype(negation_instance_v), const bool& >::value, "");

        static_assert( stdex::negation_v<std::true_type> == false, "");
        static_assert( stdex::negation_v<std::false_type> == true, "");

        // -- disjunction :

        static_assert( std::is_base_of< std::false_type, stdex::disjunction<> >::value, "");
        static_assert( stdex::disjunction<>::value == false, "");

        static_assert( stdex::disjunction<std::true_type>::value == true, "");
        static_assert( stdex::disjunction<std::false_type>::value == false, "");

        static_assert( stdex::disjunction<std::true_type,std::true_type>::value == true, "");
        static_assert( stdex::disjunction<std::true_type,std::false_type>::value == true, "");
        static_assert( stdex::disjunction<std::false_type,std::true_type>::value == true, "");
        static_assert( stdex::disjunction<std::false_type,std::false_type>::value == false, "");

        static_assert( stdex::disjunction<std::true_type,std::true_type,std::true_type>::value == true, "");
        static_assert( stdex::disjunction<std::true_type,std::true_type,std::false_type>::value == true, "");
        static_assert( stdex::disjunction<std::true_type,std::false_type,std::true_type>::value == true, "");
        static_assert( stdex::disjunction<std::false_type,std::true_type,std::true_type>::value == true, "");
        static_assert( stdex::disjunction<std::true_type,std::false_type,std::false_type>::value == true, "");
        static_assert( stdex::disjunction<std::false_type,std::true_type,std::false_type>::value == true, "");
        static_assert( stdex::disjunction<std::false_type,std::false_type,std::true_type>::value == true, "");
        static_assert( stdex::disjunction<std::false_type,std::false_type,std::false_type>::value == false, "");

        constexpr auto &disjunction_instance = stdex::static_constexpr< disjunction<std::true_type> >::value;
        static_assert( std::is_same< decltype(disjunction_instance), const disjunction<std::true_type>& >::value, "");
        constexpr auto &disjunction_instance_v = disjunction_instance.value;
        static_assert( std::is_same< decltype(disjunction_instance_v), const bool& >::value, "");

        static_assert( stdex::disjunction_v<std::true_type> == true, "");
        static_assert( stdex::disjunction_v<std::false_type> == false, "");
    }
}

BOOST_AUTO_TEST_SUITE_END()

////////////////////////////////////////////////////////////////////////////////
}// EONS SOLOTESTS
////////////////////////////////////////////////////////////////////////////////
