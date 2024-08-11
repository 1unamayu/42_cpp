/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:42:51 by xamayuel          #+#    #+#             */
/*   Updated: 2024/08/11 17:00:35 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void makeHeader(const std::string &moduleText);
void makeFish(int lineLength);

int main()
{

  makeHeader("MODULE 05 - Exercise 00 - Mommy, when I grow up, I want to be a "
             "bureaucrat!");

  std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
            << std::endl;
  std::cout << " Eneko and Elian will be created" << std::endl;
  std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
            << std::endl;
  Bureaucrat bure1("Eneko", 2);
  Bureaucrat bure2("Elian", 149);

  std::cout << bure1 << std::endl;
  std::cout << bure2 << std::endl;

  std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
            << std::endl;
  std::cout << " Eneko is going to be ascended 2 times" << std::endl;
  std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
            << std::endl;
  try
  {
    bure1.incrementGrade();
    std::cout << bure1 << std::endl;
    bure1.incrementGrade();
    std::cout << bure1 << std::endl;
  }
  catch(std::exception const &e)
  {
    std::cerr << e.what() << std::endl;
  }

  std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
            << std::endl;
  std::cout << " Elian is going to be descended 2 times " << std::endl;
  std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
            << std::endl;

  try
  {
    bure2.decrementGrade();
    std::cout << bure2 << std::endl;
    bure2.decrementGrade();
    std::cout << bure2 << std::endl;
  }
  catch(std::exception const &e)
  {
    std::cerr << e.what() << std::endl;
  }
  std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
            << std::endl;
  std::cout << " Trying to create wrong bureaucrats (xabier 0 ; Unai 151) "
            << std::endl;
  std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
            << std::endl;
  Bureaucrat bure3("Xabier", 0);
  Bureaucrat bure4("Unai", 151);
  std::cout << bure3 << std::endl;
  std::cout << bure4 << std::endl;
}
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