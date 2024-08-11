/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:07:26 by xamayuel          #+#    #+#             */
/*   Updated: 2024/08/11 18:07:32 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name(""), _signed(false), _gradeToSign(1), _gradeToExecute(1)
{
    std::cout << KBLA "AForm default constructor called" KNOR << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute)
{
    std::cout << KBLA "AForm constructor called" KNOR << std::endl;
    if(gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if(gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::~AForm(void)
{
    std::cout << KBLA "AForm destructor called" KNOR << std::endl;
}

AForm::AForm(const AForm &other)
    : _name(other._name), _signed(other._signed),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << KBLA "AForm copy constructor called" KNOR << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
    (void)other;
    return (*this);
}

std::string AForm::getName(void) const
{
    return (this->_name);
}

int AForm::getGradeToSign(void) const
{
    return (this->_gradeToSign);
}

int AForm::getGradeToExecute(void) const
{
    return (this->_gradeToExecute);
}

bool AForm::getSigned(void) const
{
    return (this->_signed);
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
    if(bureaucrat.getGrade() > this->_gradeToSign)
        throw GradeTooLowException();
    this->_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

const char *AForm::NotSignedException::what() const throw()
{
    return ("Form not signed");
}

const char *AForm::FileException::what() const throw()
{
    return ("File open error");
}

std::ostream &operator<<(std::ostream &os, AForm const &form)
{
    os << "Name: " << form.getName()
       << ", Grade to sign: " << form.getGradeToSign()
       << ", Grade to execute: " << form.getGradeToExecute()
       << ", Signed: " << form.getSigned();
    return (os);
}