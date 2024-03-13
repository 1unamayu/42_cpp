/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:18:27 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/13 12:10:33 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap(const std::string name)
{
  std::cout << KBLA "ClapTrap constructor called" KNOR << std::endl;
  _name = name;
  _attackdamage = 0;
  _energy = 10;
  _hitpoints = 10;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
  *this = src;
  std::cout << KBLA "Copy constructor called" KNOR << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
  std::cout << KBLA "ClapTrap destructor called" KNOR << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
  std::cout << KBLA "Assign constructor called" KNOR << std::endl;
  if(this != &rhs)
  {
    this->_name = rhs.getName();
    this->_hitpoints = rhs.getHit();
    this->_attackdamage = rhs.getDamage();
    this->_energy = rhs.getEnergy();
  }
  return *this;
}
// GETTERS
std::string ClapTrap::getName(void) const
{
  return _name;
}
int ClapTrap::getHit(void) const
{
  return _hitpoints;
}
int ClapTrap::getDamage(void) const
{
  return _attackdamage;
}
int ClapTrap::getEnergy(void) const
{
  return _energy;
}
std::ostream &operator<<(std::ostream &o, ClapTrap const &i)
{
  o << KPUR "          Name = " << KCYA << i.getName() << std::endl;
  o << KPUR "    Hit Points = " << KCYA << i.getHit() << std::endl;
  o << KPUR " Attack damage = " << KCYA << i.getDamage() << std::endl;
  o << KPUR " Energy Points = " << KCYA << i.getEnergy() << std::endl;
  return o;
}

void ClapTrap::attack(const std::string &target)
{
  if(_hitpoints && _energy)
  {
    std::cout << "ClapTrap " << KBLU << this->_name;
    std::cout << KNOR << " attacks " << KCYA << target;
    std::cout << KNOR << " causing " KYEL << this->getDamage() << KNOR
              << " points of damage!";
    std::cout << std::endl;
    this->_energy--;
  }
  if(_hitpoints == 0)
  {
    std::cout << KRED << "ClapTrap " << KCYA << _name
              << KRED "is already dead!";
    std::cout << std::endl;
  }
  if(_energy == 0)
  {
    std::cout << KRED << "ClapTrap " << KCYA << _name << KRED " has no energy!";
    std::cout << std::endl;
  }
}

void ClapTrap::takeDamage(unsigned int amount)
{
  if(_hitpoints == 0)
  {
    std::cout << KRED << "ClapTrap " << KCYA << _name
              << KRED "is already dead!";
    std::cout << std::endl;
    return;
  }
  std::cout << "ClapTrap " << KBLU << this->_name;
  std::cout << KNOR << " takes ";
  std::cout << KYEL << amount << KNOR << " points of damage!";
  std::cout << std::endl;
  if(amount < _hitpoints)
    _hitpoints -= amount;
  else
    _hitpoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
  if(_energy == 0)
  {
    std::cout << KRED << "ClapTrap " << KCYA << _name << KRED " has no energy!";
    std::cout << std::endl;
    return;
  }
  std::cout << KNOR << "ClapTrap " << KBLU << _name << KNOR " heals " KCYA;
  std::cout << amount << KNOR " HP!";
  std::cout << std::endl;
  this->_hitpoints = this->_hitpoints + amount;
  this->_energy--;
}
