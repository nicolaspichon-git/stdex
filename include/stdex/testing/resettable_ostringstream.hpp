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
namespace stdex { namespace testing {
////////////////////////////////////////////////////////////////////////////////

/// @ingroup stdex_nonstandard_testing
/// @brief Resettable string-buffered std::ostream-based output stream.
///
/// Usage:
///
///     stdex::testing::resettable_ostringstream os;
///     os << x;// x has an overloaded operator << for std::ostream
///     assert(os.str() == "x's output");
///     os.reset();// empty the os' internal buffer
///
class resettable_ostringstream : public std::ostream// need to be based on std::ostream
{
public:

    resettable_ostringstream()
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
}}// EONS stdex::testing
////////////////////////////////////////////////////////////////////////////////
