/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:55:45 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/23 14:09:55 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
void makeFish(int lineLength);
void makeHeader(const std::string &moduleText);

int main(void)
{
  makeHeader("MODULE 01 - ex00 - My First Class in Orthodox Canonical Form");
  Fixed a;
  Fixed b(a);
  Fixed c;

  c = b;
  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;
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