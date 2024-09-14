/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:42:51 by xamayuel          #+#    #+#             */
/*   Updated: 2024/09/08 22:21:00 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
void makeHeader(const std::string &moduleText);
void makeFish(int lineLength);
void testBureaucratAndForm();

int main()
{
    makeHeader("MODULE 05 - Exercise 01 - Form up, maggots!");

    testBureaucratAndForm();
}

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

void testBureaucratAndForm()
{
    std::cout << KYEL "\n--- Testing Bureaucrat and Form ---\n" KNOR
              << std::endl;

    try
    {
        std::cout  << KYEL <<" Creating a high rank bureaucrat and a low rank bureaucrat" << KNOR << std::endl;
        Bureaucrat highRank("HighRank", 1);
        Bureaucrat lowRank("LowRank", 150);
        

        std::cout << highRank << std::endl;
        std::cout << lowRank << std::endl;
        
        std::cout << KYEL << "Creating two forms, one with high rank and one with low rank" << KNOR << std::endl;
        Form easyForm("EasyForm", 150, 150);
        Form hardForm("HardForm", 1, 1);
        std::cout << easyForm << std::endl;
        std::cout << hardForm << std::endl;

        std::cout << KYEL "\nTrying to sign forms:" KNOR << std::endl;
        highRank.signForm(easyForm);
        highRank.signForm(hardForm);
        lowRank.signForm(easyForm);
        lowRank.signForm(hardForm);

        std::cout << KYEL "\nForm states after signing attempts:" KNOR
                  << std::endl;
        std::cout << easyForm << std::endl;
        std::cout << hardForm << std::endl;

        std::cout << KYEL "\nTrying to create invalid forms:" KNOR << std::endl;
        Form invalidHigh("TooHigh", 0, 1);
    }
    catch(std::exception &e)
    {
        std::cout << KRED "Exception caught: " << e.what() << KNOR << std::endl;
    }

    try
    {
        Form invalidLow("TooLow", 1, 151);
    }
    catch(std::exception &e)
    {
        std::cout << KRED "Exception caught: " << e.what() << KNOR << std::endl;
    }
}

