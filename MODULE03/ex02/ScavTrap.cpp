/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:21:59 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/13 12:09:35 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// DEFAULT CONSTRUCTOR
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
  std::cout << KBLA "ScavTrap " << name << " constructed!" KNOR << std::endl;
  _hitpoints = 100;
  _attackdamage = 20;
  _energy = 50;
}
// COPY CONSTRUCTOR
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
  std::cout << KBLA "ScavTrap " << _name << " copied!" KNOR << std::endl;
}

// COPY ASSIGNMENT
ScavTrap & ::ScavTrap::operator=(const ScavTrap &other)
{
  if(this != &other)
  {
    ClapTrap::operator=(other);
    std::cout << KBLA "ScavTrap " << _name << " assigned!" KNOR << std::endl;
  }
  return *this;
}
void ScavTrap::guardGate(void)
{
  std::cout << "ScavTrap " KBLU << _name << KNOR " is now in Gatekeeper mode!"
            << std::endl;
}

ScavTrap::~ScavTrap()
{
  std::cout << KBLA "ScavTrap destructor called" KNOR << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
  if(_hitpoints && _energy)
  {
    std::cout << "ScavTrap " << KBLU << this->_name;
    std::cout << KNOR << " attacks " << KCYA << target;
    std::cout << KNOR << " causing " KYEL << this->getDamage() << KNOR
              << " points of damage!";
    std::cout << std::endl;
    this->_energy--;
  }
  if(_hitpoints == 0)
  {
    std::cout << KRED << "ScavTrap " << KCYA << _name
              << KRED "is already dead!";
    std::cout << std::endl;
  }
  if(_energy == 0)
  {
    std::cout << KRED << "ScavTrap " << KCYA << _name << KRED " has no energy!";
    std::cout << std::endl;
  }
}