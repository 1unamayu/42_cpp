/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:36:53 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/11 21:49:40 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
public:
  ScavTrap(void);
  ScavTrap(std::string name); // Constructo
  ScavTrap(ScavTrap const &scavnew);
  ~ScavTrap();
};
#endif