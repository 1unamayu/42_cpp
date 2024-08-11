/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:07:11 by xamayuel          #+#    #+#             */
/*   Updated: 2024/08/11 18:07:12 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm
{
  public:
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm(void);
    RobotomyRequestForm(const RobotomyRequestForm &other);

    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

    std::string const &getTarget(void) const;

    void execute(Bureaucrat const &executor) const;

  private:
    const std::string _target;
    RobotomyRequestForm(void);
};

#endif