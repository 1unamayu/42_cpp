/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:24:38 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/13 12:11:20 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// FALTA MEJORAR EL MAIN Y COMENTAR TODO
int main()
{
  { // ClapTrap demostration
    std::cout << "Creating ClapTrap object:" << std::endl;
    ClapTrap one("Beñat");
    one.attack("Eneko");
    one.takeDamage(4);
    one.beRepaired(3);
    std::cout << one << std::endl;
  }
  { // ScavTrap demostration
    std::cout << "Creating ScavTrap object:" << std::endl;
    ScavTrap two("Elian");
    two.attack("Eneko");
    two.takeDamage(10);
    two.beRepaired(4);
    two.guardGate();
    std::cout << two;
  }
}