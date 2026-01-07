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
#include <boost/test/unit_test.hpp>

////////////////////////////////////////////////////////////////////////////////
namespace stdex { namespace tests {
////////////////////////////////////////////////////////////////////////////////

namespace StdexStaticConstexprDataset
{
    using stdex::static_constexpr;

    const auto &ga = static_constexpr<TestObjectA>::value;

    const void *GetGlobalTestObjectA_Identifier()
    {
        return ga.id();
    }

    // unused :

    int TestObjectB::count = 0;
}

////////////////////////////////////////////////////////////////////////////////
}}// EONS stdex::tests
////////////////////////////////////////////////////////////////////////////////
