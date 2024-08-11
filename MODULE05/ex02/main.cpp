#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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

    Bureaucrat bureaucrat("Xamayuel", 2);

    RobotomyRequestForm robotomyRequestForm("Xamayuel_Robotomy");
    ShrubberyCreationForm shrubberyCreationForm("Xamayuel_Shrubbery");
    PresidentialPardonForm presidentialPardonForm("Xamayuel_Presidential");

    std::cout << "--------------- SHRUBBERY ---------------" << std::endl;
    bureaucrat.signForm(shrubberyCreationForm);
    bureaucrat.executeForm(shrubberyCreationForm);

    std::cout << "--------------- ROBOTOMY ---------------" << std::endl;
    bureaucrat.signForm(robotomyRequestForm);
    bureaucrat.executeForm(robotomyRequestForm);
    bureaucrat.executeForm(robotomyRequestForm);
    bureaucrat.executeForm(robotomyRequestForm);
    std::cout << "--------------- PRESIDENTIAL ---------------" << std::endl;
    bureaucrat.signForm(presidentialPardonForm);
    bureaucrat.executeForm(presidentialPardonForm);
}