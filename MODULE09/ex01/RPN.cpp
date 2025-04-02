#include "RPN.hpp"

RPN::RPN()
{

}

RPN::~RPN()
{

}
bool RPN::esOperadorValido(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::evaluate(std::string s)
{
    std::cout << "\033[33mEvaluating: " << "\033[0m" << s << std::endl;
    
    // check if the expression is empty
    if (s.empty())
    {
        std::cerr << "\033[1;31mError: Expression empty.\033[0m" << std::endl;
        return;
    }
    
    for (size_t i = 0; i < s.length(); ++i)
    {
        if (std::isdigit(s[i]))
        {
            if (i + 1 < s.length() && std::isdigit(s[i + 1]))
            {
                std::cerr << "\033[1;31mError: only one digit numbers.\033[0m" << std::endl;
                return;
            }
            int numero = s[i] - '0';
            _stack.push(numero);
        }
        else if (esOperadorValido(s[i]))
        {
            if (_stack.size() < 2)
            {
                std::cerr << "\033[1;31mError: not enough operands.\033[0m" << std::endl;
                return;
            }
            
            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();
            
            int resultado;
            switch (s[i])
            {
                case '+':
                    resultado = a + b;
                    break;
                case '-':
                    resultado = a - b;
                    break;
                case '*':
                    resultado = a * b;
                    break;
                case '/':
                    if (b == 0)
                    {
                        std::cerr << "\033[1;31mError: Division by zero.\033[0m" << std::endl;
                        return;
                    }
                    resultado = a / b;
                    break;
            }
            
            _stack.push(resultado);
            
        } else if (s[i] == ' ')
        {
            continue;
        }
        else
        {
            std::cerr << "\033[1;31mError: Invalid character '" << s[i] << "'.\033[0m" << std::endl;
            return;
        }
    }
    
    if (_stack.size() != 1)
    {
        std::cerr << "\033[1;31mError: Invalid RPN expression, there are operands left.\033[0m" << std::endl;
        return;
    }
    
    std::cout << "\033[1;32mResultado: " << "\033[0m"<< _stack.top() << std::endl;
}