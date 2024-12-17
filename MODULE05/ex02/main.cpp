#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void makeHeader(const std::string &moduleText);
void makeFish(int lineLength);
void testShrubberyCreationForm();
void testRobotomyRequestForm();
void testPresidentialPardonForm();
void testExceptions();

int main()
{
    makeHeader("MODULE 05 - Exercise 02 - No, you need form 28B, not 28C...");

    Bureaucrat bureaucrat("Xamayuel", 2);
    
    std::cout << KYEL "\n--- Testing Forms ---\n" KNOR << std::endl;
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

    testShrubberyCreationForm();
    testRobotomyRequestForm();
    testPresidentialPardonForm();
    testExceptions();
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

void testShrubberyCreationForm()
{
    std::cout << KYEL "\n--- Testing ShrubberyCreationForm ---\n" KNOR << std::endl;

    ShrubberyCreationForm shrubberyForm("home");
    Bureaucrat highRank("HighRank", 1);
    Bureaucrat lowRank("LowRank", 150);

    std::cout << shrubberyForm << std::endl;

    lowRank.signForm(shrubberyForm);
    highRank.signForm(shrubberyForm);

    lowRank.executeForm(shrubberyForm);
    highRank.executeForm(shrubberyForm);

    std::cout << shrubberyForm << std::endl;
}

void testRobotomyRequestForm()
{
    std::cout << KYEL "\n--- Testing RobotomyRequestForm ---\n" KNOR << std::endl;

    RobotomyRequestForm robotomyForm("Bender");
    Bureaucrat mediumRank("MediumRank", 45);

    std::cout << robotomyForm << std::endl;

    mediumRank.signForm(robotomyForm);
    
    for (int i = 0; i < 5; ++i)
    {
        mediumRank.executeForm(robotomyForm);
    }
    std::cout << robotomyForm << std::endl;
}

void testPresidentialPardonForm()
{
    std::cout << KYEL "\n--- Testing PresidentialPardonForm ---\n" KNOR << std::endl;

    PresidentialPardonForm pardonForm("Zaphod Beeblebrox");
    Bureaucrat president("President", 1);
    Bureaucrat vicePresident("VicePresident", 20);

    std::cout << pardonForm << std::endl;

    vicePresident.signForm(pardonForm);
    vicePresident.executeForm(pardonForm);

    president.executeForm(pardonForm);
    std::cout << pardonForm << std::endl;
}

void testExceptions()
{
    std::cout << KYEL "\n--- Testing Exceptions ---\n" KNOR << std::endl;

    try
    {
        Bureaucrat tooHigh("TooHigh", 0);
    }
    catch(std::exception& e)
    {
        std::cout << KRED "Exception: " << e.what() << KNOR << std::endl;
    }

    try
    {
        Bureaucrat tooLow("TooLow", 151);
    }
    catch(std::exception& e)
    {
        std::cout << KRED "Exception: " << e.what() << KNOR << std::endl;
    }

    ShrubberyCreationForm shrubberyForm("park");
    Bureaucrat lowRank("LowRank", 150);

    lowRank.signForm(shrubberyForm);
    try
    {
        lowRank.executeForm(shrubberyForm);
    }
    catch(std::exception& e)
    {
        std::cout << KRED "Exception: " << e.what() << KNOR << std::endl;
    }

    
}

