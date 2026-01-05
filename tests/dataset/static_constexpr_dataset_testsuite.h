//------------------------------------------------------------------------------
//
// Copyright (c) 2020 Nicolas Pichon
//
// Distributed under the Boost Software License, Version 1.0.
//    (See http://www.boost.org/LICENSE_1_0.txt)
//
//------------------------------------------------------------------------------
#pragma once
#include <iostream>

////////////////////////////////////////////////////////////////////////////////
namespace SoloTests {
////////////////////////////////////////////////////////////////////////////////

namespace StdexStaticConstexprDataset
{
    class TestObjectA
    {
    public:
        TestObjectA() = default;// implicitly constexpr constructor (all non-static members are initialized)
        const void *id() const { return self; }
        int data() const { return a; }
        void setdata(int a_) { a = a_; }
    private:
        const void *self = this;
        int a = 1;
    };

    const void *GetGlobalTestObjectA_Identifier();

    // unused :

    class TestObjectB
    {
    public:
        TestObjectB()
            : id(++count)
        {
            std::cout << "TestObjectA() : [id:" << id << "]" << std::endl;
        }
        virtual ~TestObjectB()
        {
            std::cout << "~TestObjectA() : [id:" << id << "]" << std::endl;
        }
    protected:
        int id = 0;
    private:
        static int count;
    };

    class TestObjectC : public TestObjectB
    {
    public:
        TestObjectC()
        {
            std::cout << "TestObjectB() : [id:" << id << "]" << std::endl;
        }

        ~TestObjectC()
        {
            std::cout << "~TestObjectB() : [id:" << id << "]" << std::endl;
        }
    private:
        TestObjectB b{};
    };
}

////////////////////////////////////////////////////////////////////////////////
}// EONS SOLOTESTS
////////////////////////////////////////////////////////////////////////////////
