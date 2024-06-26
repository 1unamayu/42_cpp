/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:48:20 by xamayuel          #+#    #+#             */
/*   Updated: 2024/04/23 16:48:21 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat()
{
  std::cout << KBLA "WRONGCAT.Default constructor called" KNOR << std::endl;
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
