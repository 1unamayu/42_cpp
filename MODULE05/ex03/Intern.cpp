/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:45:58 by xamayuel          #+#    #+#             */
/*   Updated: 2024/08/11 19:00:53 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern constructor called" << std::endl;
}

Intern::~Intern()
{
    std::cout << KBLA "Intern destructor called" KNOR << std::endl;
}

Intern::Intern(const Intern &other)
{
    *this = other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    ShrubberyCreationForm sh = ShrubberyCreationForm(target);
    RobotomyRequestForm ro = RobotomyRequestForm(target);
    PresidentialPardonForm pr = PresidentialPardonForm(target);

    AForm *forms[] = {&sh, &ro, &pr};

    for(int i = 0; i < 3; i++)
    {
        if(forms[i]->getName() == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (forms[i]->getCopy());
        }
    }
    return NULL;
}