/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:47:35 by xamayuel          #+#    #+#             */
/*   Updated: 2024/04/23 17:44:13 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	*(this->_brain) = *(rhs._brain);
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
Brain *Dog::getBrain(void) const
{
	return (this->_brain);
}
/* ************************************************************************** */
