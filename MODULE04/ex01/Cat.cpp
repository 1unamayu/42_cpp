/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:47:27 by xamayuel          #+#    #+#             */
/*   Updated: 2024/04/23 17:44:30 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

Cat::Cat(const Cat &src) : Animal()
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
	*(this->_brain) = *(rhs._brain);
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
Brain *Cat::getBrain(void) const
{
	return (this->_brain);
}
/* ************************************************************************** */
