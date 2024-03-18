#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat()
{
  std::cout << KBLA "CAT.Default constructor called" KNOR << std::endl;
  type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal()
{
  std::cout << KBLA "WRONGCAT.Copy constructor called" KNOR << std::endl;
  type = src.type;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat()
{
  std::cout << KBLA "WRONGCAT.Destructor is called" KNOR << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat &WrongCat::operator=(WrongCat const &rhs)
{
  if(this != &rhs)
  {
    this->type = rhs.getType();
  }
  return *this;
}

std::ostream &operator<<(std::ostream &o, WrongCat const &i)
{
  o << "Type = " << i.getType();
  return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void WrongCat::makeSound() const
{
  std::cout << KBLU "Miau!!!!" KNOR << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */