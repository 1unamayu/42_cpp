#include "WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal()
{
  type = "Animal";
  std::cout << KBLA "WRONGANIMAL:Default constructor called" KNOR << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
  type = src.type;
  std::cout << KBLA "WRONGANIMAL:Copy constructor called" KNOR << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal()
{
  std::cout << KBLA "WRONGANIMAL.Destructor is called" KNOR << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs)
{
  std::cout << KBLA "WRONGANIMAL.Copy assignment constructor called" KNOR
            << std::endl;
  if(this != &rhs)
  {
    this->type = rhs.getType();
  }

  return *this;
}

std::ostream &operator<<(std::ostream &o, WrongAnimal const &i)
{
  o << "Type = " << i.getType();
  return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void WrongAnimal::makeSound() const
{
  std::cout << KYEL "Generic animal sound!" KNOR << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string WrongAnimal::getType() const
{
  return this->type;
}