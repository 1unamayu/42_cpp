/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:55:45 by xamayuel          #+#    #+#             */
/*   Updated: 2024/04/03 12:18:58 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>
void makeBeach(int lineLength);
void makeHeader(const std::string &moduleText);

int main(void)
{
  makeHeader("MODULE 01 - ex03 - BSP (Binary space partitioning)");
  Point const a = Point(Fixed(0), Fixed(0));
  Point const b = Point(Fixed(3), Fixed(0));
  Point const c = Point(Fixed(0), Fixed(5.5f));

  std::cout << KGRE "--------" KNOR << std::endl;
  std::cout << KGRE "TRIANGLE" KNOR << std::endl;
  std::cout << KGRE "--------" KNOR << std::endl;
  std::cout << "a = " KBLU << a.getX() << "," << a.getY() << KNOR << std::endl;
  std::cout << "b = " KBLU << b.getX() << "," << b.getY() << KNOR << std::endl;
  std::cout << "c = " KBLU << c.getX() << "," << c.getY() << KNOR << std::endl;

  std::cout << "Point 2,2 in triangle? " KRED << bsp(a, b, c, Point(2, 2))
            << KNOR << std::endl; // false
  std::cout << "Point 2,0 in triangle? " KRED << bsp(a, b, c, Point(2, 0))
            << KNOR << std::endl; // false
  std::cout << "Point 0,2 in triangle? " KRED << bsp(a, b, c, Point(0, 2))
            << KNOR << std::endl; // false
  std::cout << "Point 5.55,0 in triangle? " KRED
            << bsp(a, b, c, Point(5.55f, 0)) << KNOR << std::endl; // false
  std::cout << "Point 0,5.55 in triangle? " KRED
            << bsp(a, b, c, Point(0, 5.55f)) << KNOR << std::endl; // false

  std::cout << "Point 2,.1 in triangle? " KGRE << bsp(a, b, c, Point(2, 0.1f))
            << KNOR << std::endl; // true
  std::cout << "Point 0.1,2 in triangle? " KGRE << bsp(a, b, c, Point(0.1f, 2))
            << KNOR << std::endl; // true
  std::cout << "Point 0.01,2 in triangle? " KGRE << bsp(a, b, c, Point(0.01f, 2))
            << KNOR << std::endl; // true
  std::cout << KGRE "-------------" KNOR << std::endl;
  std::cout << KGRE " NOT TRIANGLE" KNOR << std::endl;
  std::cout << KGRE "-------------" KNOR << std::endl;
  std::cout << "a = " KBLU << a.getX() << "," << a.getY() << KNOR << std::endl;
  std::cout << "b = " KBLU << b.getX() << "," << b.getY() << KNOR << std::endl;
  std::cout << "c = " KBLU << a.getX() << "," << a.getY() << KNOR << std::endl;
  std::cout << "Point 0.1,2 in triangle? " KRED << bsp(a, b, a, Point(0.1f, 2))
            << std::endl; // false
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