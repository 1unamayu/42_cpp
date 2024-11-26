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
void testCreateBureaucrats();
void testIncrementBureaucrat(Bureaucrat &bure1);
void testDecrementBureaucrat(Bureaucrat &bure2);
void testInvalidBureaucrats();

int main()
{
  makeHeader("MODULE 05 - Exercise 00 - Mommy, when I grow up, I want to be a "
             "bureaucrat!");

  testCreateBureaucrats();

  Bureaucrat bure1("Eneko", 2);
  Bureaucrat bure2("Elian", 149);

  testIncrementBureaucrat(bure1);
  testDecrementBureaucrat(bure2);
  testInvalidBureaucrats();
}

void testCreateBureaucrats()
{
  std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
            << std::endl;
  std::cout << " Eneko y Elian serán creados" << std::endl;
  std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
            << std::endl;
  Bureaucrat bure1("Eneko", 2);
  Bureaucrat bure2("Elian", 149);

  std::cout << bure1 << std::endl;
  std::cout << bure2 << std::endl;
}

void testIncrementBureaucrat(Bureaucrat &bure1)
{
  std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
            << std::endl;
  std::cout << " Eneko va a ser ascendido 2 veces" << std::endl;
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
}

void testDecrementBureaucrat(Bureaucrat &bure2)
{
  std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
            << std::endl;
  std::cout << " Elian va a ser descendido 2 veces " << std::endl;
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
}

void testInvalidBureaucrats()
{
  std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
            << std::endl;
  std::cout << " Intentando crear burócratas incorrectos (Xabier 0 ; Unai 151) "
            << std::endl;
  std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
            << std::endl;
  try
  {
    Bureaucrat bure3("Xabier", 0);
  }
  catch(std::exception const &e)
  {
    std::cerr << e.what() << std::endl;
  }
  try
  {
    Bureaucrat bure4("Unai", 151);
  }
  catch(std::exception const &e)
  {
    std::cerr << e.what() << std::endl;
  }
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