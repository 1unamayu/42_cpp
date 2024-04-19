#include "AAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AAnimal::AAnimal()
{
  type = "Animal";
  std::cout << KBLA "Animal.Default constructor called" KNOR << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
  type = src.type;
  std::cout << KBLA "AAnimal.Copy constructor called" KNOR << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AAnimal::~AAnimal()
{
  std::cout << KBLA "ANIMAL.Destructor is called" KNOR << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AAnimal &AAnimal::operator=(AAnimal const &rhs)
{
  std::cout << KBLA "AAnimal.Copy assignment constructor called" KNOR
            << std::endl;
  if(this != &rhs)
  {
    this->type = rhs.getType();
  }

  return *this;
}

std::ostream &operator<<(std::ostream &o, AAnimal const &i)
{
  o << "Type = " << i.getType();
  return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void AAnimal::makeSound() const
{
  std::cout << KYEL "Generic animal sound!" KNOR << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string AAnimal::getType() const
{
  return this->type;
}
/* ************************************************************************** */
