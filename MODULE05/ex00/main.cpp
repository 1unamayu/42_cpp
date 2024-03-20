/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:42:51 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/20 17:04:04 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// FALTA HACER MAIN
int main()
{
  std::cout << KRED "-----------------------" KNOR << std::endl;
  std::cout << KRED "MODULE 04 - Exercise:00" KNOR << std::endl;
  std::cout << KRED "-----------------------" KNOR << std::endl;
  std::cout << LBLU "               O  o" << std::endl;
  std::cout << KCYA "          _\\_ " LBLU "  o" << std::endl;
  std::cout << KPUR ">('>" KCYA "   \\\\/  o\\" LBLU " . " << std::endl;
  std::cout << KCYA "       //\\___=" << std::endl;
  std::cout << std::endl;

  Bureaucrat bure1("Beñat", 2);
  Bureaucrat bure2("Elian", 149);

  std::cout << KRED << bure1.getName();
  std::cout << std::endl;
  std::cout << bure1.getGrade();
  std::cout << std::endl;
  std::cout << bure1;
  try
  {
    bure1.incrementGrade();
    bure1.incrementGrade();
  }
  catch(std::exception const &e)
  {
    std::cerr << e.what() << std::endl;
  }

  std::cout << bure1;
  std::cout << bure2;
  try
  {
    bure2.decrementGrade();
    bure2.decrementGrade();
  }
  catch(std::exception const &e)
  {
    std::cerr << e.what() << std::endl;
  }
}