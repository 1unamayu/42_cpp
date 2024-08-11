/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:47:12 by xamayuel          #+#    #+#             */
/*   Updated: 2024/04/23 16:47:14 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal()
{
  type = "Animal";
  std::cout << KBLA "Animal.Default constructor called" KNOR << std::endl;
}

Animal::Animal(const Animal &src)
{
  type = src.type;
  std::cout << KBLA "Animal.Copy constructor called" KNOR << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
  std::cout << KBLA "ANIMAL.Destructor is called" KNOR << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &Animal::operator=(Animal const &rhs)
{
  std::cout << KBLA "Animal.Copy assignment constructor called" KNOR
            << std::endl;
  if(this != &rhs)
  {
    this->type = rhs.getType();
  }

  return *this;
}

std::ostream &operator<<(std::ostream &o, Animal const &i)
{
  o << "Type = " << i.getType();
  return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void Animal::makeSound() const
{
  std::cout << KYEL "Generic animal sound!" KNOR << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string Animal::getType() const
{
  return this->type;
}
/* ************************************************************************** */
