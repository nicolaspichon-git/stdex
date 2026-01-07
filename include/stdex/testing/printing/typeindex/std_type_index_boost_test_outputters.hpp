//------------------------------------------------------------------------------
//
// Copyright (c) 2020 Nicolas Pichon
//
// Distributed under the Boost Software License, Version 1.0.
//    (See http://www.boost.org/LICENSE_1_0.txt)
//
//------------------------------------------------------------------------------
#pragma once

#include <Solo/Core/Testing/Printing/typeindex/std_type_index_testing_outputters.h>

////////////////////////////////////////////////////////////////////////////////

namespace std
{
    /// @ingroup SoloCoreTesting
    /// @brief Ready-to-use <c>std::type_info</c> boost test's printer.
    /// @note Need to be declared in the same namespace than the type to print.
    inline ostream &boost_test_print_type(ostream &os, type_info const &ti)
    {
        return ::solo::testing::operator<<(os, ti);
    }

    /// @ingroup SoloCoreTesting
    /// @brief Ready-to-use <c>std::type_index</c> boost test's printer.
    /// @note Need to be declared in the same namespace than the type to print.
    inline ostream &boost_test_print_type(ostream &os, type_index const &ti)
    {
        return ::solo::testing::operator<<(os, ti);
    }

}// EONS STD

////////////////////////////////////////////////////////////////////////////////

