#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(std::string const name, int toSign, int toExecute)
    : _name(name), _gradeToSign(toSign), _gradeToExcecute(toExecute),
      _signed(false)
{
    std::cout << KBLA "FORM.Default constructor called" KNOR << std::endl;
    if(toSign < 1 || toSign > 150)
    {
        throw std::invalid_argument("tosign must be between 1 and 150");
    }
    if(toExecute < 1 || toExecute > 150)
    {
        throw std::invalid_argument("toExecute must be between 1 and 150");
    }
}

Form::Form(const Form &src)
    : _name(src._name), _gradeToSign(src._gradeToSign),
      _gradeToExcecute(src._gradeToExcecute), _signed(src._signed)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
    std::cout << KBLA "FORM.Default destructor called" KNOR << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &Form::operator=(Form const &rhs)
{

    if(this != &rhs)
    {
        this->_signed = rhs._signed;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &o, Form const &i)
{
    o << KCYA << std::setw(19) << std::right << i.getName();
    o << KNOR ": form ";
    if(i.isSigned())
        o << KGRE << "signed" << KNOR << ". ";
    else
        o << KRED << "not signed" << KNOR << ". ";
    o << std::endl << std::setw(21) << "";
    o << KBLU << "Grade to sign: " << KNOR << i.getGradeToSign();
    o << std::endl << std::setw(21) << "";
    o << KPUR << "Grade to execute: " << KNOR << i.getGradeToExecute()
      << std::endl;
    o << KNOR;
    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void Form::beSigned(const Bureaucrat &bureaucrat)
{
    try
    {
        if(this->getGradeToSign() < bureaucrat.getGrade())
            throw GradeTooLowException();
    }
    catch(const GradeTooLowException &e)
    {
        std::cout << KRED << "GRADE to low" << KNOR << std::endl;
        return;
    }
    if(this->getGradeToSign() >= bureaucrat.getGrade())
    {
        this->_signed = true;
        std::cout << KBLU << "<" << this->getName() << "> is signed by <"
                  << bureaucrat.getName() << ">" << KNOR << std::endl;
    }
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/
int Form::getGradeToSign(void) const
{
    return (_gradeToSign);
}
int Form::getGradeToExecute(void) const
{
    return (_gradeToExcecute);
}

bool Form::isSigned(void) const
{
    return (_signed);
}
std::string Form::getName(void) const
{
    return (_name);
}
/*
** --------------------------------- EXCEPTIONS-------------------------------
*/

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}


/* ************************************************************************** */