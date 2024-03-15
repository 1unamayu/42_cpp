/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 10:41:02 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/09 12:18:34 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"
#include <string>
/**
 * @brief Class representing a human with a name and a weapon
 *
 */
class HumanB
{
private:
  std::string _name; ///< The name of the human
  Weapon *_weapon;   ///< Pointer to the weapon the human is holding

public:
  HumanB();                       ///< Default constructor
  HumanB(std::string name);       ///< Constructor with name parameter
  ~HumanB();                      ///< Destructor
  void attack();                  ///< Method for the human to attack
  void setWeapon(Weapon &weapon); ///< Method to set the weapon for the human
};
#endif
