/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:39:06 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/11 21:50:51 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
  std::cout << KBLA "ScavTrap constructor called" KNOR << std::endl;
  
}
ScavTrap::~ScavTrap(){
  std::cout << KBLA "ScavTrap destructor called" KNOR << std::endl;

}