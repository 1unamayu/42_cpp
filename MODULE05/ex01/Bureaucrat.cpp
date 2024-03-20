#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
    std::cout << KBLA "BUREAUCRAT.Default constructor called" KNOR << std::endl;
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

    o << KCYA << std::setw(10) << i.getName() << KNOR ": bureaucrat grade "
      << KBLU << i.getGrade();
    o << KNOR << std::endl;
    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void Bureaucrat::incrementGrade()
{
    _grade = _grade - 1;
    if(_grade < 1)
        throw Bureaucrat::GradeTooLowException();
}
void Bureaucrat::decrementGrade()
{
    _grade = _grade + 1;
    if(_grade > 150)
        throw Bureaucrat::GradeTooHighException();
}

void signForm(Form &form)
{
    (void)form;
    std::cout << "hola" << std::endl;
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
/*
** ------------------------------- EXCEPTIONS --------------------------------
*/
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "BureaucratException: Grade too High";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "BureaucratException: Grade too Low";
}
/* ************************************************************************** */