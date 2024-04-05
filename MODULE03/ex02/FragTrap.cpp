/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:34:05 by xamayuel          #+#    #+#             */
/*   Updated: 2024/04/05 12:27:19 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
  std::cout << KBLA "FragTrap " << this->_name << " constructed!" KNOR
            << std::endl;
  _hitpoints = 100;
  _attackdamage = 30;
  _energy = 100;
}
FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
  std::cout << KBLA "FragTrap " << name << " constructed!" KNOR << std::endl;
  _hitpoints = 100;
  _attackdamage = 30;
  _energy = 100;
}

// copy
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
  std::cout << KBLA "FragTrap " << _name << " copied!" KNOR << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
  if(this != &other)
  {
    ClapTrap::operator=(other);
    std::cout << KBLA "FragTrap " << _name << " assigned!" KNOR << std::endl;
  }
  return *this;
}
FragTrap::~FragTrap()
{
  std::cout << KBLA "FragTrap destructor called" KNOR << std::endl;
}

void FragTrap::highFivesGuy()
{
  if(_hitpoints)
  {
    std::cout << "FragTrap " KBLU << _name << KNOR
              << " requests a high five! Up top, fellow human!" << std::endl;
  }
}