//------------------------------------------------------------------------------
//
// Copyright (c) 2021 Nicolas Pichon
//
// Distributed under the Boost Software License, Version 1.0.
//    (See http://www.boost.org/LICENSE_1_0.txt)
//
//------------------------------------------------------------------------------

#include <stdex/is_nothrow_invocable.hpp>
#include <boost/test/unit_test.hpp>

////////////////////////////////////////////////////////////////////////////////
namespace stdex { namespace tests {
////////////////////////////////////////////////////////////////////////////////

namespace
{
    bool ff_test_success() noexcept { return true; };
    bool ff_test_failure() { return true; };
}

//..............................................................................

BOOST_AUTO_TEST_SUITE( StdexFunctionalBoostTestSuite )

//..............................................................................

BOOST_AUTO_TEST_CASE( IsNothrowInvocableTest )
{
    using stdex::is_nothrow_invocable;

    {
        // avoid gcc warning "function 'xxx' is not needed and will not be emitted"
        BOOST_TEST((ff_test_success()));
        BOOST_TEST((ff_test_failure()));

        static_assert(noexcept(ff_test_success()),"");
        static_assert(noexcept(ff_test_failure()) == false,"");
    }

    {
        // until c++14 : noexcept is not part of the function type -> is_nothrow_invocable gives bad result with free function
        // since c++17 : noexcept is part of the function type -> ok
//        static_assert(is_nothrow_invocable<decltype(ff_test_success)>::value,"");
//        static_assert(is_nothrow_invocable<decltype(ff_test_failure)>::value == false,"");
    }

    {
        const auto fl_test_success = []() noexcept {};
        static_assert(is_nothrow_invocable<decltype(fl_test_success)>::value,"");

        const auto fl_test_failure = [](){};
        static_assert(is_nothrow_invocable<decltype(fl_test_failure)>::value == false,"");
    }

    {
        struct fl_test_success_t
        {
            void operator()() noexcept {};
        };
        static_assert(is_nothrow_invocable<fl_test_success_t>::value,"");

        struct fl_test_failure_t
        {
            void operator()() {};
        };
        static_assert(is_nothrow_invocable<fl_test_failure_t>::value == false,"");
    }

    //... (member function pointers, etc.)
}

BOOST_AUTO_TEST_SUITE_END()

////////////////////////////////////////////////////////////////////////////////
}}// EONS stdex::tests
////////////////////////////////////////////////////////////////////////////////
