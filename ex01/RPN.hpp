#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <algorithm>
#include <stack>

class RPN
{
    private:
        std::stack<int> numbers;
    public:
        RPN();
        ~RPN();
        RPN(const RPN& original);
        RPN& operator=(const RPN& original);
        void calculate(std::string& expression);
};


#endif