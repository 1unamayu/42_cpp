#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
  std::cout << KBLA "DOG.Default constructor called" KNOR << std::endl;
  type = "Dog";
  _brain = new Brain;
}

Dog::Dog(const Dog &src) : Animal()
{
  std::cout << KBLA "DOG.Copy constructor called" KNOR << std::endl;
  _brain = new Brain(*src._brain);
  type = src.type;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
  std::cout << KBLA "DOG.Destructor is called" KNOR << std::endl;
  delete _brain;
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
void Dog::setIdea(std::string idea, int index)
{
  this->_brain->ideas[index] = idea;
}

std::string Dog::getIdea(int index)
{
  return (this->_brain->ideas[index]);
}
/* ************************************************************************** */
