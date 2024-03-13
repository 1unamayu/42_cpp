/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:20:18 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/13 13:37:30 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
  ScavTrap(const std::string &name);          // Default constructor
  ScavTrap(const ScavTrap &other);            // Copy constructor
  ScavTrap &operator=(const ScavTrap &other); // Copy assignment operator
  ~ScavTrap();                                // Default destructor
  void guardGate(void);                       // guard function
  void attack(const std::string &target);     // New attack
};

#endif