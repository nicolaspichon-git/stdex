//------------------------------------------------------------------------------
//
// Copyright (c) 2021 Nicolas Pichon
//
// Distributed under the Boost Software License, Version 1.0.
//    (See http://www.boost.org/LICENSE_1_0.txt)
//
//------------------------------------------------------------------------------
#pragma once

#include <ostream>
#include <sstream>

////////////////////////////////////////////////////////////////////////////////
namespace stdex { namespace tests { namespace helpers {
////////////////////////////////////////////////////////////////////////////////

// custom std::ostream-based output stream

/// @ingroup SoloCoreTesting
/// @brief Ready-to-use std::ostream-based output stream.
///
/// usage :
///
///     solo::testing::testing_ostream os;
///     os << x;// x has an overloaded operator << for std::ostream
///     assert(os.str() == "content x is supposed to output");
///     os.reset();// empty the os' internal buffer
///
class testing_ostream : public std::ostream// need to be based on std::ostream
{
public:

    testing_ostream()
        : std::ostream(&m_sbuffer)
    {}

    std::string str() const
    {
        return m_sbuffer.str();
    }

    void reset()
    {
        m_sbuffer.str("");
    }

private:
    std::stringbuf m_sbuffer;
};

////////////////////////////////////////////////////////////////////////////////
}}}// EONS stdex::tests::helpers
////////////////////////////////////////////////////////////////////////////////
