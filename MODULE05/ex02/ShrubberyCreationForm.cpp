/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:09:59 by xamayuel          #+#    #+#             */
/*   Updated: 2024/08/11 19:13:48 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("ShrubberyCreationForm", 145, 137), _target("")
{
    std::cout << "ShrubberyCreationForm default constructor called"
              << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    (void)other;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    std::cout << "ShrubberyCreationForm execute called" << std::endl;
    
    if(this->getSigned() == false)
        throw AForm::NotSignedException();
    if(executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::ofstream file((_target + "_shrubbery").c_str());

    if(!file.is_open())
        throw AForm::FileException();


    file << "    ccee88oo" << std::endl;
    file << "  C8O8O8Q8PoOb o8oo" << std::endl;
    file << " dOB69QO8PdUOpugoO9bD" << std::endl;
    file << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
    file << "    6OuU  /p u gcoUodpP" << std::endl;
    file << "      \\\\\\//  /douUP" << std::endl;
    file << "        \\\\\\////" << std::endl;
    file << "         |||/\\" << std::endl;
    file << "         |||\\/" << std::endl;
    file << "         |||||" << std::endl;
    file << "   .....//||||\\...." << std::endl;
    file.close();
}