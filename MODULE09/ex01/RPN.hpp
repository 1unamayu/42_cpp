
#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
class RPN
{
   public:
    RPN();
    ~RPN();
    void evaluate(std::string s);

    private:
    std::stack<int> _stack;
    bool esOperadorValido(char c);
    bool ultimoCaracterEsOperador(const std::string& s);
};
#endif