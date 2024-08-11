#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), _target("")
{
    std::cout << KBLA "PresidentialPardonForm default constructor called" KNOR
              << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << KBLA "PresidentialPardonForm constructor called" KNOR
              << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << KBLA "PresidentialPardonForm destructor called" KNOR
              << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other), _target(other._target)
{
    std::cout << KBLA "PresidentialPardonForm copy constructor called" KNOR
              << std::endl;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    (void)other;
    return (*this);
}

std::string PresidentialPardonForm::getTarget(void) const
{
    return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if(this->getSigned() == false)
        throw AForm::NotSignedException();
    if(executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox."
              << std::endl;
}

AForm *		PresidentialPardonForm::getCopy( void )const
{
	AForm* copy = new PresidentialPardonForm(*this);
	return (copy);
}