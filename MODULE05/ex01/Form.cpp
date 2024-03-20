#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(std::string const name, int toSign, int toExecute)
    : _name(name), _gradeToSign(toSign), _gradeToExcecute(toExecute), _signed(false)
{
    std::cout << KBLA "FORM.Default constructor called" KNOR << std::endl;
    
}

Form::Form(const Form &src)
    : _signed(src._signed), _name(src._name),
      _gradeToExcecute(src._gradeToExcecute), _gradeToSign(src._gradeToSign)
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
    
    if ( this != &rhs )
    {
     this->_signed = rhs._signed;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &o, Form const &i)
{
    (void)i;
    // o << "Value = " << i.getValue();
    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
int Form::getGradeToSign(void) const
{
    return (_gradeToSign);
}
int Form::getGradeToExecute(void) const
{
    return (_gradeToExcecute);
}

bool Form::isSigned(void) const{
    return(_signed);
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */