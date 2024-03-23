/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 10:48:05 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/23 14:06:16 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/**
 * @brief Default constructor for HumanB class
 *
 */
HumanB::HumanB()
{
}

/**
 * @brief Constructor for HumanB class with name parameter
 *
 * @param name The name of the human
 */
HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
  std::cout << KBLA << "HumanB created" << std::endl;
}

/**
 * @brief Destructor for HumanB class
 *
 */
HumanB::~HumanB()
{
  std::cout << KBLA << "HumanB destroyed" << std::endl;
}

/**
 * @brief Method for the human to attack with their weapon
 *
 */
void HumanB::attack()
{
  std::cout << KRED << this->_name << KNRM;
  std::cout << KGRN << " attacks with their " << KNRM;
  if(this->_weapon == NULL)
  {
    std::cout << KBLU << "NOTHING" << KNRM;
    std::cout << std::endl;
  }
  else
  {
    std::cout << KBLU << this->_weapon->getType() << KNRM;
    std::cout << std::endl;
  }
}

/**
 * @brief Method to set the weapon for the human
 *
 * @param addweapon The weapon to be set
 */
void HumanB::setWeapon(Weapon &addweapon)
{
  this->_weapon = &addweapon;
}
