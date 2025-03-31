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

bool RPN::ultimoCaracterEsOperador(const std::string& s)
{
    for (std::string::const_reverse_iterator it = s.rbegin(); it != s.rend(); ++it)
    {
        if (*it != ' ')
        {
            return esOperadorValido(*it);
        }
    }
    return false;
}

void RPN::evaluate(std::string s)
{
    if (s.empty() || s.find_first_not_of("0123456789+-*/ ") == std::string::npos)
    {
        std::cerr << "Error" << std::endl;
        return;
    }

    if (!ultimoCaracterEsOperador(s))
    {
        std::cerr << "Error" << std::endl;
        return;
    }

    for (size_t i = 0; i < s.length(); ++i)
    {
        if (std::isdigit(s[i]))
        {
            int numero = s[i] - '0';
            _stack.push(numero);
        }
        else if (esOperadorValido(s[i]))
        {
            if (_stack.size() < 2)
            {
                std::cerr << "Error" << std::endl;
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
                        std::cerr << "Error" << std::endl;
                        return;
                    }
                    resultado = a / b;
                    break;
            }
            
            _stack.push(resultado);
        }
        else if (s[i] == ' ')
        {
            continue;
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return;
        }
    }
    std::cout << _stack.top() << std::endl;
}