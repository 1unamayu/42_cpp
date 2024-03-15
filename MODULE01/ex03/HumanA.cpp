/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 10:08:17 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/09 12:18:04 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/**
 * @brief HumanA constructor
 *
 * @param name The name of the human
 * @param weapon The weapon the human will use
 */
HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
  std::cout << KBLA << "HumanA created" << std::endl;
}

/**
 * @brief HumanA destructor
 *
 */
HumanA::~HumanA()
{
  std::cout << KBLA << "HumanA destroyed" << std::endl;
}

/**
 * @brief Method for the human to attack using their weapon
 *
 */
void HumanA::attack()
{
  std::cout << KRED << this->_name << KNRM;
  std::cout << KGRN << " attacks with their " << KNRM;
  std::cout << KBLU << this->_weapon.getType() << KNRM;
  std::cout << std::endl;
}
