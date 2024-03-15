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
// CLASS
class HumanB
{
private:
  std::string _name; ///< The name of the human
  Weapon *_weapon;   ///< Pointer to the weapon the human is holding

public:
  HumanB();                       // DEFAULT CONSTRUCTOR
  HumanB(std::string name);       // CONSTRUCTOR WITH NAME
  ~HumanB();                      // DESTRUCTOR
  void attack();                  // METHOD TO ATTACK
  void setWeapon(Weapon &weapon); // WEAPON SETTER
};
#endif
