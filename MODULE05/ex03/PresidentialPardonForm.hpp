/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:07:19 by xamayuel          #+#    #+#             */
/*   Updated: 2024/08/11 18:59:55 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm
{
  public:
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm(void);
    PresidentialPardonForm(const PresidentialPardonForm &other);

    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

    std::string getTarget(void) const;

    void execute(Bureaucrat const &executor) const;
    virtual  AForm* getCopy(void) const;

  private:
    const std::string _target;
    PresidentialPardonForm(void);
};

#endif