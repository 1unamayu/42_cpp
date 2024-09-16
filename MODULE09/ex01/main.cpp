
#include <iostream>
#include "RPN.hpp"
int main(int argn, char *argv[])
{
    if (argn != 2)
    {
        std::cerr << "\033[1;31mError: Invalid number of arguments\033[0m" << std::endl;
        return 1;
    }
    std::string s = argv[1];
     RPN rpn;
 
    rpn.evaluate(s);
    return 0;
}