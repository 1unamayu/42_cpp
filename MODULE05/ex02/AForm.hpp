/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:07:14 by xamayuel          #+#    #+#             */
/*   Updated: 2024/08/11 18:07:15 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm
{
  public:
    AForm(std::string name, const int gradeToSign, const int gradeToExecute);
    AForm(AForm const &src);
    ~AForm(void);

    AForm &operator=(AForm const &rhs);

    std::string getName(void) const;
    bool getSigned(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;

    void beSigned(Bureaucrat const &bureaucrat);

    virtual void execute(Bureaucrat const &executor) const = 0;

    class GradeTooHighException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };

    class NotSignedException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };

    class FileException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };

  private:
    std::string const _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;
    AForm(void);
};

std::ostream &operator<<(std::ostream &o, AForm const &rhs);
#endif