/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:42:51 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/20 18:42:54 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
void makeFish()
{
  std::cout << LBLU "               O  o" << std::endl;
  std::cout << KCYA "          _\\_ " LBLU "  o" << std::endl;
  std::cout << KPUR ">('>" KCYA "   \\\\/  o\\" LBLU " . " << std::endl;
  std::cout << KCYA "       //\\___=" << std::endl;
  std::cout << std::endl;
}
void makeHeader(const std::string& moduleText) {
 int lineLength = moduleText.length() + 2; // Adjust for extra spaces
 std::string line = std::string(lineLength, '-');

 std::cout << KRED << line << KNOR << std::endl;
 std::cout << KRED << " " << moduleText << " " << KNOR << std::endl;
 std::cout << KRED << line << KNOR << std::endl;
}
// FALTA HACER MAIN
int main()
{
    makeFish();
    makeHeader("MODULE 05 - Exercise 01 - Form up, maggots!");

    Bureaucrat bure1("Beñat", 2);
}