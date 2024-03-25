/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:55:45 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/25 12:11:08 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>
void makeBeach(int lineLength);
void makeHeader(const std::string &moduleText);
bool bsp(Point  a, Point  b, Point c, Point  point) {
    // Calculate vectors
    Point  v0 = c;
    v0 = v0 - a;
    Point v1 = b;
    v1 = v1 - a;
    Point v2 = point;
    v2 = v2 - a;

    // Compute dot products
    float dot00 = (v0.getX() * v0.getX() + v0.getY() * v0.getY()).toFloat();
    float dot01 = (v0.getX() * v1.getX() + v0.getY() * v1.getY()).toFloat();
    float dot02 = (v0.getX() * v2.getX() + v0.getY() * v2.getY()).toFloat();
    float dot11 = (v1.getX() * v1.getX() + v1.getY() * v1.getY()).toFloat();
    float dot12 = (v1.getX() * v2.getX() + v1.getY() * v2.getY()).toFloat();

    // Compute barycentric coordinates
    float invDenom = 1 / (dot00 * dot11 - dot01 * dot01);
    float u = (dot11 * dot02 - dot01 * dot12) * invDenom;
    float v = (dot00 * dot12 - dot01 * dot02) * invDenom;

    // Check if point is inside triangle
    return (u >= 0) && (v >= 0) && (u + v < 1);
}
int main(void)
{
  makeHeader("MODULE 01 - ex03 - BSP (Binary space partitioning)");
  Point const a  = Point(Fixed(10), Fixed(0));
  Point const b = Point(Fixed(4), Fixed(0));
  Point const c = Point(Fixed(0), Fixed(4));

  Point const d = Point(Fixed(2), Fixed(2));
  bsp(a,b,c,d);
  
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