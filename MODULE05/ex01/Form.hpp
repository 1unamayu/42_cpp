#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
class Form;
#include "Bureaucrat.hpp"
class Form
{
  private:
    const std::string _name;
    const int _gradeToSign;
    const int _gradeToExcecute;
    bool _signed;
    Form();

  public:
    Form(std::string const name, int toSign, int toExecute);
    Form(Form const &src);
    ~Form();

    Form &operator=(Form const &rhs);
    
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
    void beSigned(Bureaucrat const &bure);

    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;
    bool isSigned(void) const;
    std::string getName(void) const;
};

std::ostream &operator<<(std::ostream &o, Form const &i);

#endif
