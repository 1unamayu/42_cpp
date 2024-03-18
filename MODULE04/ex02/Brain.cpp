#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain()
{
  std::cout << KBLA "BRAIN:Default constructor called" KNOR << std::endl;
  for(int z = 0; z < 100; z++)
  {
    ideas[z] = "NO_IDEA";
  }
}

Brain::Brain(const Brain &src)
{
  std::cout << KBLA "BRAIN:Default constructor called" KNOR << std::endl;
  for(int i = 0; i < 100; i++)
  {
    ideas[i] = src.ideas[i];
  }
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
  std::cout << KBLA "BRAIN:Desstructor called" KNOR << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &Brain::operator=(Brain const &rhs)
{
  std::cout << KBLA "BRAIN:Copy assignment constructor called" KNOR
            << std::endl;
  if(this != &rhs)
  {
    this->ideas[0] = rhs.ideas[0];
  }
  return *this;
}

std::ostream &operator<<(std::ostream &o, Brain const &i)
{
  for(int j = 0; j < 100; j++)
  {
    o << "Idea " << j << " = " << i.ideas[j] << std::endl;
  }

  return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
