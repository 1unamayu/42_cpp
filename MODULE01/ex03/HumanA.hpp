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
/**
 * @brief Class representing a human with a name and a weapon
 *
 */
class HumanA
{
private:
  std::string _name; ///< The name of the human
  Weapon &_weapon;   ///< Reference to the weapon the human is holding

public:
  /**
   * @brief Constructor for HumanA class
   *
   * @param name The name of the human
   * @param weapon The weapon the human is holding
   */
  HumanA(std::string name, Weapon &weapon);

  /**
   * @brief Destructor for HumanA class
   *
   */
  ~HumanA();

  /**
   * @brief Method for the human to attack using their weapon
   *
   */
  void attack();
};
#endif