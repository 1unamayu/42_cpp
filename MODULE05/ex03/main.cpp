/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:01:25 by xamayuel          #+#    #+#             */
/*   Updated: 2024/09/08 23:29:37 by xamayuel         ###   ########.fr       */
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
void printTestDescription(const std::string &description)
{
    std::cout << KYEL << "\n============================================== " << description << " ======================================================" << KNOR << std::endl;
}

void testIntern()
{
    printTestDescription("Inter Creation");

    Intern someRandomIntern;

    printTestDescription("Creating Boss Bureacrat");
   
    Bureaucrat boss("Boss", 1);

    std::cout
        << KBLU
        << "======================================================== RobotomyRequestForm ===================================================="
        << KNOR << std::endl;
    AForm *rrf;
    rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
    if(rrf)
    {

        std::cout << *rrf << std::endl;
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf; // Add this line
    }
    std::cout << KBLU
              << "======================================== ShrubberyCreationForm "
                 "========================================"
              << KNOR << std::endl;
    AForm *scf;

    scf = someRandomIntern.makeForm("ShrubberyCreationForm", "Garden");

    if(scf)
    {

        std::cout << *scf << std::endl;
        boss.signForm(*scf);
        boss.executeForm(*scf);
        delete scf;
    }
    AForm *ppf;

    ppf = someRandomIntern.makeForm("PresidentialPardonForm", "Zaphod");

    if(ppf)
    {
        std::cout << KBLU
                  << "======================================================== PresidentialPardonForm "
                     "============================================================"
                  << KNOR << std::endl;
        std::cout << *ppf << std::endl;
        boss.signForm(*ppf);
        boss.executeForm(*ppf);
        delete ppf;
    }
    std::cout << KBLU
              << "================================================== NonExistentForm ===================================================="
              << KNOR << std::endl;
    AForm *nonExistentForm;
    nonExistentForm = someRandomIntern.makeForm("non existent", "Nobody");
    if(nonExistentForm)
    {

        std::cout << *nonExistentForm << std::endl;
        delete nonExistentForm;
    }
    else
    {
        std::cout << "Intern couldn't create the non-existent form."
                  << std::endl;
    }
    std::cout << KRED
              << "============================================================== CLOSING ========================================================"
              << KNOR << std::endl;
}

int main()
{
    makeHeader("Module 05 - Ex 03");

    std::cout << KGRE
              << "This program tests the Intern class and its ability to "
                 "create different types of forms."
              << KNOR << std::endl;
    std::cout << KGRE
              << "We will create an Intern and ask it to make various forms, "
                 "including:"
              << KNOR << std::endl;
    std::cout << KGRE << "  - RobotomyRequestForm" << KNOR << std::endl;
    std::cout << KGRE << "  - ShrubberyCreationForm" << KNOR << std::endl;
    std::cout << KGRE << "  - PresidentialPardonForm" << KNOR << std::endl;
    std::cout << KGRE << "  - A non-existent form" << KNOR << std::endl;
    std::cout << KGRE
              << "For each valid form, we will sign and execute it using a "
                 "high-level Bureaucrat."
              << KNOR << std::endl;
    std::cout << KGRE << "Let's begin the tests!" << KNOR << std::endl;

    testIntern();

    return 0;
}