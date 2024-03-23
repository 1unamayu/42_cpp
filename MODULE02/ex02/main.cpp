/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:55:45 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/23 15:46:42 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
void makeBeach(int lineLength);
void makeHeader(const std::string &moduleText);
int main(void)
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