#include "Bureaucrat.hpp"
#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
    std::cout << KBLA "BUREAUCRAT.Default constructor called" KNOR << std::endl;
    if(grade < 1)
    {
       throw Bureaucrat::GradeTooHighException();
    }
    if(grade > 150)
    {
       throw Bureaucrat::GradeTooLowException();
    }
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
    : _name(src._name), _grade(src._grade)
{
    std::cout << KBLA "BUREAUCRAT.Copy constructor called" KNOR << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
    std::cout << KBLA "BUREAUCRAT.Destructor called" KNOR << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    std::cout << KBLA "BUREAUCRAT.Copy operator called" KNOR << std::endl;
    if(this != &rhs)
    {

        this->_grade = rhs.getGrade();
    }
    return *this;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{

    o << KCYA << std::setw(19) << std::right << i.getName()
      << KNOR ": bureaucrat grade " << KBLU << i.getGrade();
    o << KNOR;
    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void Bureaucrat::incrementGrade()
{
    _grade = _grade - 1;
    if(_grade < 1)
        throw Bureaucrat::GradeTooHighException();
}
void Bureaucrat::decrementGrade()
{
    _grade = _grade + 1;
    if(_grade > 150)
        throw Bureaucrat::GradeTooLowException(); 
}

void Bureaucrat::signForm(AForm &form)
{
    if(form.getGradeToSign() >= this->getGrade())
    {
        form.beSigned(*this);
        std::cout << KBLU << "<" << this->getName() << "> signs <"
                  << form.getName() << ">" << KNOR << std::endl;
    }
    else
        std::cout << KRED << "<" << this->getName() << "> cannot sign <"
                  << form.getName()
                  << "> because <the bureaucrat's grade is lower than the "
                     "form's grade to sign>"
                  << KNOR << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

void Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        form.execute(*this);
        std::cout << KBLU << "<" << this->getName() << "> executes <"
                  << form.getName() << ">" << KNOR << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << KRED << "<" << this->getName() << "> cannot execute <"
                  << form.getName() << "> because <" << e.what() << ">" << KNOR
                  << std::endl;
    }
}
/*
** ------------------------------- EXCEPTIONS --------------------------------
*/
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return SUBR "BureaucratException" KRED ": " NEGR "Grade too High" KNOR;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return SUBR "BureaucratException" KRED ": " NEGR "Grade too Low" KNOR;
}
/* ************************************************************************** */