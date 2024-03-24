/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:55:45 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/24 12:52:05 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <string>

void makeHeader(const std::string &moduleText);
void makeBeach(int lineLength);

/**
 * @brief Main function that executes the program.
 *
 * @return int
 */
int main(void)
{
    makeHeader(
        "MODULE 01 - ex01 - Towards a more useful fixed-point number class");
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

    a = Fixed(1234.4321f);
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << "--" << b.getRawBits() << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
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
              << KBLU "   _____ _ __ __ ____ _ " KGRE "| __/o\\\\ _"
              << std::endl;

    std::cout << std::string(lineLength / 2, ' ')
              << KBLU " =-=-_-__=_-= _=_=-=_" KGRE ",-'|\"'\"\"-|-,_"
              << std::endl;
    std::cout << std::string(lineLength / 2, ' ')
              << KBLU "  =- _=-=- -_=-=_" KGRE ",-\"          |" << std::endl;
    std::cout << std::string(lineLength / 2, ' ')
              << KBLU "    =- =- -=.--" KGRE "\"" << std::endl;
    std::cout << std::endl;
}