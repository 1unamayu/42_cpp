/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:01:25 by xamayuel          #+#    #+#             */
/*   Updated: 2024/08/11 19:04:25 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

void makeFish(int lineLength)
{
    lineLength = lineLength - 16;
    std::cout << KBLU "               @@@@@@@" KPUR "  *@@@@@@@@@@@@"
              << std::endl;
    std::cout << KBLU "           @@@@@@     " KPUR "*@@@#  @@@@@@"
              << std::endl;
    std::cout << KBLU "        @@@@@@@       " KPUR "*@     @@@@@@"
              << std::endl;
    std::cout << KBLU "      @@@@@@,         " KPUR "      @@@@@@/"
              << std::endl;
    std::cout << KBLU "   &@@@@@@            " KPUR "   #@@@@@@" << std::endl;
    std::cout << KBLU " @@@@@@(              " KPUR " @@@@@@&" << std::endl;
    std::cout << KBLU "@@@@@@@@@@@@@@@@@@@@  " KPUR "*@@@@@@    /@"
              << std::endl;
    std::cout << KBLU "@@@@@@@@@@@@@@@@@@@@  " KPUR "*@@@@@@  @@@@"
              << std::endl;
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
    makeHeader("MODULE 05 - Exercise 02 - No, you need form 28B, not 28C...");

    std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
    try
    {
        Intern someRandomIntern;
        AForm * form;
        form = someRandomIntern.makeForm("shrubbery creation", "Xamayuel");
        std::cout << *form << std::endl;
        
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}