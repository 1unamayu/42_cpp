/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:42:51 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/20 19:27:41 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
void makeFish(int lineLength)
{
	lineLength = lineLength -16;
  std::cout << std::string(lineLength/2, ' ') << LBLU "               O  o" << std::endl;
  std::cout << std::string(lineLength/2, ' ')<< KCYA "          _\\_ " LBLU "  o" << std::endl;
  std::cout << std::string(lineLength/2, ' ')<< KPUR ">('>" KCYA "   \\\\/  o\\" LBLU " . " << std::endl;
  std::cout << std::string(lineLength/2, ' ')<< KCYA "       //\\___=" << std::endl;
  std::cout << std::endl;
}
void makeHeader(const std::string& moduleText) {
 int lineLength = moduleText.length() + 2; // Adjust for extra spaces
 
 std::string line = std::string(lineLength, '-');
 std::cout << KRED << line << KNOR << std::endl;
 std::cout << KRED << " " << moduleText << " " << KNOR << std::endl;
 std::cout << KRED << line << KNOR << std::endl;
 makeFish(lineLength);
 std::cout << KRED << line << KNOR << std::endl;

}
// FALTA HACER MAIN
int main()
{
    makeHeader("MODULE 05 - Exercise 01 - Form up, maggots!");

    Bureaucrat bure1("Beñat", 2);
}