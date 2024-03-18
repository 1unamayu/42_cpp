#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
  std::cout << KBLA "DOG.Default constructor called" KNOR << std::endl;
  type = "Dog";
}

Dog::Dog(const Dog &src) : Animal(src)
{
  std::cout << KBLA "DOG.Copy constructor called" KNOR << std::endl;
  type = src.type;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
  std::cout << KBLA "DOG.Destructor is called" KNOR << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &Dog::operator=(Dog const &rhs)
{
  if(this != &rhs)
  {
    this->type = rhs.getType();
  }
  return *this;
}

std::ostream &operator<<(std::ostream &o, Dog const &i)
{
  o << "Type = " << i.getType();
  return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void Dog::makeSound() const
{
  std::cout << KRED "Guau!!!!" KNOR << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */