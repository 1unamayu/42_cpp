/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:42:51 by xamayuel          #+#    #+#             */
/*   Updated: 2024/08/11 17:14:25 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
void makeFish(int lineLength)
{
  lineLength = lineLength - 16;
  std::cout << KBLU "               @@@@@@@" KPUR "  *@@@@@@@@@@@@"
            << std::endl;
  std::cout << KBLU "           @@@@@@     " KPUR "*@@@#  @@@@@@" << std::endl;
  std::cout << KBLU "        @@@@@@@       " KPUR "*@     @@@@@@" << std::endl;
  std::cout << KBLU "      @@@@@@,         " KPUR "      @@@@@@/" << std::endl;
  std::cout << KBLU "   &@@@@@@            " KPUR "   #@@@@@@" << std::endl;
  std::cout << KBLU " @@@@@@(              " KPUR " @@@@@@&" << std::endl;
  std::cout << KBLU "@@@@@@@@@@@@@@@@@@@@  " KPUR "*@@@@@@    /@" << std::endl;
  std::cout << KBLU "@@@@@@@@@@@@@@@@@@@@  " KPUR "*@@@@@@  @@@@" << std::endl;
  std::cout << KBLU "             @@@@@@@" << std::endl;
  std::cout << KGRE " (xamayuel)" KBLU "  @@@@@@@                     "
            << std::endl;
  std::cout << std::endl;
}
void makeHeader(const std::string &moduleText)
{
  int lineLength = moduleText.length() + 2; // Adjust for extra spaces

  std::string line = std::string(lineLength, '-');
  std::cout << KRED << line << KNOR << std::endl;
  std::cout << KRED << " " << moduleText << " " << KNOR << std::endl;
  std::cout << KRED << line << KNOR << std::endl;
  makeFish(lineLength);
  std::cout << KRED << line << KNOR << std::endl;
}

int main()
{
    makeHeader("MODULE 05 - Exercise 01 - Form up, maggots!");

    Bureaucrat bure1("Beniat", 2);
    Form formu("Viajes", 1, 2);

    std::cout << bure1 << std::endl;
    std::cout << formu << std::endl;
}