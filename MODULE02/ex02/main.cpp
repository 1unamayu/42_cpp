/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:55:45 by xamayuel          #+#    #+#             */
/*   Updated: 2024/04/03 13:19:38 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
void makeBeach(int lineLength);
void makeHeader(const std::string &moduleText);
int main(void)
{
  {
    makeHeader("MODULE 01 - ex02 - Now we’re talking");
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << KBLU << a << std::endl;
    std::cout << KBLU << ++a << std::endl;
    std::cout << KBLU << a << std::endl;
    std::cout << KBLU << a++ << std::endl;
    std::cout << KBLU << a << std::endl;

    std::cout << KCYA << b << std::endl;
    std::cout << KCYA << Fixed::max(a, b) << std::endl;
  }
  {
    makeHeader("MODULE 01 - ex02 - Now we’re talking - testing");
    Fixed a(2);
    Fixed b(5.0f);
    Fixed c;

    std::cout << KCYA << "Incremets and decrements test" << std::endl;
    std::cout << KCYA << "-----------------------------" << std::endl;
    std::cout << KBLU << "  a =" << a << std::endl;
    std::cout << KBLU << "--a =" << --a << std::endl;
    std::cout << KBLU << "  a =" << a << std::endl;
    std::cout << KBLU << "a++ =" << a++ << std::endl;
    std::cout << KBLU << "  a =" << a << std::endl;
    std::cout << KCYA << "-----------------------------" << std::endl;
    std::cout << KBLU << "b   =" << b << std::endl;
    std::cout << KBLU << "++b =" << ++b << std::endl;
    std::cout << KBLU << "b   =" << b << std::endl;
    std::cout << KBLU << "b-- =" << b-- << std::endl;
    std::cout << KBLU << "b   =" << b << std::endl;
    std::cout << KCYA << "Arithmetics operators" << std::endl;
    std::cout << KCYA << "-----------------------------" << std::endl;
    c = a + b;
    std::cout << KBLU << "a + b = " << c << std::endl;
    c = a - b;
    std::cout << KBLU << "a - c =" << c << std::endl;
    c = a * b;
    std::cout << KBLU << "a * b =" << c << std::endl;

    c = b / a;
    std::cout << KBLU << "b / a =" << c << std::endl;
    c = a / b;
    std::cout << KBLU << "a / b =" << c << std::endl;

    std::cout << KCYA << "Maximum and minimum" << std::endl;
    std::cout << KCYA << "-----------------------------" << std::endl;
    std::cout << KBLU << "MAX(A,B) = " << Fixed::max(a, b) << std::endl;
    std::cout << KBLU << "MIN(A,B) = " << Fixed::min(a, b) << std::endl;
    std::cout << KCYA << "-----------------------------" << std::endl;
    Fixed const d(4);
    Fixed const e(3.9f);
    std::cout << KCYA << "-----------------------------" << std::endl;
    std::cout << KBLU << "MAX(D,E) = " << Fixed::max(d, e) << std::endl;
    std::cout << KBLU << "MIN(E,D) = " << Fixed::min(e, d) << std::endl;

    std::cout << KCYA << "Comparison operators" << std::endl;
    std::cout << KCYA << "-----------------------------" << std::endl;
    std::cout << KBLU << "a == b = " << (a == b) << std::endl;
    std::cout << KBLU << "a != b = " << (a != b) << std::endl;
    std::cout << KBLU << "a <  b = " << (a < b) << std::endl;
    std::cout << KBLU << "a <= b = " << (a <= b) << std::endl;
    std::cout << KBLU << "a >  b = " << (a > b) << std::endl;
    std::cout << KBLU << "a >= b = " << (a >= b) << std::endl;

    std::cout << KBLU << "b <= b = " << (b <= b) << std::endl;
    std::cout << KBLU << "b >= b = " << (b >= b) << std::endl;
    std::cout << KCYA << "-----------------------------" << std::endl;
    std::cout << KBLU << "c == d = " << (c == d) << std::endl;
    std::cout << KBLU << "c != d = " << (c != d) << std::endl;
    std::cout << KBLU << "c <  d = " << (c < d) << std::endl;
    std::cout << KBLU << "c <= d = " << (c <= d) << std::endl;
    std::cout << KBLU << "c >  d = " << (c > d) << std::endl;
    std::cout << KBLU << "c >= d = " << (c >= d) << std::endl;

    std::cout << KBLU << "c <= d = " << (c <= d) << std::endl;
    std::cout << KBLU << "c >= d = " << (c >= d) << std::endl;
  }
  {
  }
}

/**
 * @brief  Function to create a header with a given text.
 *
 * @param moduleText Text of the module.
 */
void makeHeader(const std::string &moduleText)
{
  int lineLength = moduleText.length() + 2; // Adjust for extra spaces

  std::string line = std::string(lineLength, '-');
  std::cout << KRED << line << KNOR << std::endl;
  std::cout << KRED << " " << moduleText << " " << KNOR << std::endl;
  std::cout << KRED << line << KNOR << std::endl;
  makeBeach(lineLength);
  std::cout << KRED << line << KNOR << std::endl;
}
/**
 * @brief Function to create a visual representation of a beach.
 *
 * @param lineLength Length of the beach line.
 */
void makeBeach(int lineLength)
{

  lineLength = lineLength - 30;
  std::cout << std::string(lineLength / 2, ' ') << KYEL "          |"
            << std::endl;

  std::cout << std::string(lineLength / 2, ' ') << KYEL "        \\ _ /"
            << std::endl;
  std::cout << std::string(lineLength / 2, ' ') << KYEL "      -= (_) =-"
            << std::endl;
  std::cout << std::string(lineLength / 2, ' ')
            << KYEL "        /   \\     " KGRE "    _\\/_" << std::endl;
  std::cout << std::string(lineLength / 2, ' ')
            << KYEL "          |        " KGRE "   //o\\  _\\/_" << std::endl;
  std::cout << std::string(lineLength / 2, ' ')
            << KBLU "   _____ _ __ __ ____ _ " KGRE "| __/o\\\\ _" << std::endl;

  std::cout << std::string(lineLength / 2, ' ')
            << KBLU " =-=-_-__=_-= _=_=-=_" KGRE ",-'|\"'\"\"-|-,_"
            << std::endl;
  std::cout << std::string(lineLength / 2, ' ')
            << KBLU "  =- _=-=- -_=-=_" KGRE ",-\"          |" << std::endl;
  std::cout << std::string(lineLength / 2, ' ')
            << KBLU "    =- =- -=.--" KGRE "\"" << std::endl;
  std::cout << std::endl;
}