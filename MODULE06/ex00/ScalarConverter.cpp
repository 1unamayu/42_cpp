/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:23:00 by xamayuel          #+#    #+#             */
/*   Updated: 2024/08/11 22:13:12 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>
#include <string>
#include <limits.h>
// Static member variables initialization

std::string ScalarConverter::_literal;
char ScalarConverter::_char;
int ScalarConverter::_int;
float ScalarConverter::_float;
double ScalarConverter::_double;
bool ScalarConverter::_pseudoliteral;

//Default constructor
ScalarConverter::ScalarConverter()
{
  std::cout << KBLA "ScalarConverter constructor called" KNOR << std::endl;
}

// Destructor
ScalarConverter::~ScalarConverter()
{
  std::cout << KBLA "ScalarConverter destructor called" KNOR << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
  *this = other;
  return;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
  (void)other;
  _char = other._char;
  _int = other._int;
  _float = other._float;
  _double = other._double;
  _pseudoliteral = other._pseudoliteral;
  return (*this);
}

const char *ScalarConverter::InvalidLiteralException::what() const throw()
{
  return ("Invalid literal");
}

bool ScalarConverter::_isPseudoLiteral(std::string str)
{
  return (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" ||
          str == "-inf" || str == "-inff");
}

bool ScalarConverter::_isChar(std::string str)
{
  return (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]));
}

bool ScalarConverter::_isInt(std::string str)
{
  if(str.empty())
    return false;

  size_t i = 0;
  if(str[0] == '+' || str[0] == '-')
    i++;

  if(i == str.length())
    return false;

  for(; i < str.length(); i++)
  {
    if(!std::isdigit(str[i]))
      return false;
  }
  return true;
}

bool ScalarConverter::_isDouble(std::string str)
{
  if(str.empty())
    return false;

  size_t i = 0;
  bool hasDecimalPoint = false;

  // Check for optional sign
  if(str[0] == '+' || str[0] == '-')
    i++;

  // String can't be just a sign
  if(i == str.length())
    return false;

  for(; i < str.length(); i++)
  {
    if(str[i] == '.')
    {
      // Can't have more than one decimal point
      if(hasDecimalPoint)
        return false;
      hasDecimalPoint = true;
    }
    else if(!std::isdigit(str[i]))
    {
      return false;
    }
  }

  // Must have at least one digit
  return hasDecimalPoint && (i > 1);
}

bool ScalarConverter::_isFloat(std::string str)
{
  if(str.empty())
    return false;

  size_t i = 0;
  bool hasDecimalPoint = false;

  // Check for optional sign
  if(str[0] == '+' || str[0] == '-')
    i++;

  // String can't be just a sign
  if(i == str.length())
    return false;

  for(; i < str.length() - 1; i++)
  {
    if(str[i] == '.')
    {
      // Can't have more than one decimal point
      if(hasDecimalPoint)
        return false;
      hasDecimalPoint = true;
    }
    else if(!std::isdigit(str[i]))
    {
      return false;
    }
  }

  // Check if the last character is 'f' or a digit
  if(str[str.length() - 1] != 'f' && !std::isdigit(str[str.length() - 1]))
    return false;

  // Must have at least one digit and a decimal point
  return hasDecimalPoint && (i > 1);
}
void ScalarConverter::printChar(double value)
{
  if(value < 0 || value > 127)
    throw InvalidLiteralException();
  if(std::isprint(value))
    std::cout << "char: " << static_cast<char>(value) << std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::convert(std::string str)
{
  if(_isPseudoLiteral(str))
  {
    std::cout << "  char: impossible" << std::endl;
    std::cout << "   int: impossible" << std::endl;
    if(str == "nanf" || str == "+inff" || str == "-inff")
      std::cout << " float: " << str << std::endl;
    else
      std::cout << " float: " << str << "f" << std::endl;
    if(str == "nan" || str == "+inf" || str == "-inf")
      std::cout << "double: " << str << std::endl;
    else
      std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
    return;
  }
  if(_isChar(str))
  {
    std::cout << "  char: '" << str[0] << "'" << std::endl;
    std::cout << "   int: " << static_cast<int>(str[0]) << std::endl;
    std::cout << " float: " << static_cast<float>(str[0]) << std::endl;
    std::cout << "double: " << static_cast<double>(str[0]) << std::endl;
    return;
  }

  if(_isInt(str))
  {
    std::istringstream iss(str);

    float temp;
    iss >> temp;
    
    if(temp > INT_MAX || temp < INT_MIN)
    {
        std::cout << "  char: impossible" << std::endl;
        std::cout << "   int: impossible" << std::endl;
        std::cout << " float: " << static_cast<float>(temp) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(temp) << std::endl;
        return;
    }
    if(temp > 31 && temp < 127)
      std::cout << "  char: '" << static_cast<char>(temp) << "'" << std::endl;
    else
      std::cout << "  char: Non displayable" << std::endl;
    std::cout << "   int: " << temp << std::endl;
    std::cout << " float: " << std::fixed << std::setprecision(1)
              << static_cast<float>(temp) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1)
              << static_cast<double>(temp) << std::endl;
    return;
  }
  if(_isFloat(str))
  {
    std::string numStr = str;
    if(str[str.length() - 1] == 'f')
        numStr = str.substr(0, str.length() - 1);
        
    std::istringstream iss(numStr);
    float value;
    iss >> value;
    
    if(value > 31 && value < 127)
        std::cout << "  char: '" << static_cast<char>(value) << "'" << std::endl;
    else
        std::cout << "  char: Non displayable" << std::endl;

    if(value > INT_MAX || value < INT_MIN)
        std::cout << "   int: impossible" << std::endl;
    else
        std::cout << "   int: " << static_cast<int>(value) << std::endl;

    std::cout << " float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
    
    return;
  }

  std::cout << "  char: Non displayable" << std::endl;
  std::cout << "   int: Non displayable" << std::endl;
  std::cout << " float: Non displayable" << std::endl;
  std::cout << "double: Non displayable" << std::endl;
}
