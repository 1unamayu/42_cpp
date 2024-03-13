/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:24:38 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/13 12:47:09 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
// FALTA MEJORAR EL MAIN Y COMENTAR TODO
int main()
{
   // Demonstrate ClapTrap
    std::cout << "Creating ClapTrap object:" << std::endl;
    ClapTrap claptrap("CL4P-TP");
    claptrap.attack("Bandit");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);

    // Demonstrate ScavTrap
    std::cout << "\nCreating ScavTrap object:" << std::endl;
    ScavTrap scavtrap("SC4V-TP");
    scavtrap.attack("Bandit");
    scavtrap.takeDamage(10);
    scavtrap.beRepaired(5);
    scavtrap.guardGate();

    // Demonstrate FragTrap
    std::cout << "\nCreating FragTrap object:" << std::endl;
    FragTrap fragtrap("FR4G-TP");
    fragtrap.attack("Bandit");
    fragtrap.takeDamage(15);
    fragtrap.beRepaired(10);
    fragtrap.highFivesGuy();
}