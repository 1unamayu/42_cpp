/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 10:41:07 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/09 12:20:19 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"
// CLASS
class HumanA
{
private:
  std::string _name; // The name of the human
  Weapon &_weapon;   // Reference to the weapon the human is holding

public:
  HumanA(std::string name, Weapon &weapon); // CONSTRUCTOR WITH NAME AND WEAPON

  ~HumanA(); // DEFAULT DESTRUCTOR

  void attack(); // ATTACK METHOD
};
#endif
