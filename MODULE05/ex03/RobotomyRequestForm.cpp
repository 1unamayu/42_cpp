/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:07:07 by xamayuel          #+#    #+#             */
/*   Updated: 2024/08/11 19:00:27 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << KBLA "RobotomyRequestForm constructor called" KNOR
              << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(void)
    : AForm("RobotomyRequestForm", 72, 45), _target("")
{
    std::cout << KBLA "RobotomyRequestForm default constructor called" KNOR
              << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), _target(other._target)
{
    std::cout << KBLA "RobotomyRequestForm copy constructor called" KNOR
              << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << KBLA "RobotomyRequestForm destructor called" KNOR << std::endl;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if(this != &other)
        AForm::operator=(other);
    return *this;
}

std::string const &RobotomyRequestForm::getTarget(void) const
{
    return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    int i;

    if(this->getSigned() == false)
        throw AForm::NotSignedException();
    if(executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "Drilling noises..." << std::endl;
    i = rand() % 2;
    if(i == 0)
        std::cout << this->_target << " has been robotomized successfully."
                  << std::endl;
    else
        std::cout << this->_target << " robotomy failed." << std::endl;
}

AForm *		RobotomyRequestForm::getCopy( void )const
{
	AForm* copy = new RobotomyRequestForm(*this);
	return (copy);
}
