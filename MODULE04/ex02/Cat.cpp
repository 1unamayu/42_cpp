#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
  std::cout << KBLA "CAT.Default constructor called" KNOR << std::endl;
  type = "Cat";
  _brain = new Brain;
}

Cat::Cat(const Cat &src) : AAnimal()
{
  std::cout << KBLA "CAT.Copy constructor called" KNOR << std::endl;
  _brain = new Brain(*src._brain);
  type = src.type;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
  std::cout << KBLA "CAT.Destructor is called" KNOR << std::endl;
  delete _brain;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &Cat::operator=(Cat const &rhs)
{

  if(this != &rhs)
  {
    this->type = rhs.getType();
  }
  return *this;
}

std::ostream &operator<<(std::ostream &o, Cat const &i)
{

  o << "Type = " << i.getType();
  return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Cat::makeSound() const
{
  std::cout << KBLU "Miau!!!!" KNOR << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/
void Cat::setIdea(std::string idea, int index)
{
  this->_brain->ideas[index] = idea;
}

std::string Cat::getIdea(int index)
{
  return (this->_brain->ideas[index]);
}
/* ************************************************************************** */
