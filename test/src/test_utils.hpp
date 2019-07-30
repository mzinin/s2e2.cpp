#pragma once

#include <any>
#include <stack>


namespace TestUtils
{
    template <class ... Args>
    std::stack<std::any> createStack(Args ... args)
    {
        return std::stack<std::any>{std::stack<std::any>::container_type{args...}};
    }

} // namespace TestUtils
