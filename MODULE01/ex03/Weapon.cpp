/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:21:40 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/09 12:16:25 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/**
 * @brief Weapon constructor with type parameter
 *
 * @param newtype The type of the weapon
 */
Weapon::Weapon(std::string newtype) : _type(newtype)
{
  std::cout << KBLA << "Weapon created" << std::endl;
}

/**
 * @brief Default Weapon constructor
 *
 */
Weapon::Weapon()
{
}

/**
 * @brief Weapon destructor
 *
 */
Weapon::~Weapon()
{
  std::cout << KBLA << "Weapon destroyed" << std::endl;
}

/**
 * @brief Get the type of the weapon
 *
 * @return const std::string& The type of the weapon
 */
const std::string &Weapon::getType()
{
  return this->_type;
}

/**
 * @brief Set the type of the weapon
 *
 * @param newtype The new type of the weapon
 */
void Weapon::setType(const std::string &newtype)
{
  this->_type = newtype;
}
