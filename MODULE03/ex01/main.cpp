/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:24:38 by xamayuel          #+#    #+#             */
/*   Updated: 2024/04/05 12:11:35 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// FALTA HACER BUEN MAIN
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
void makeHeader(const std::string &moduleText);
void makeDolphin(int lineLength);
int main()
{
  {
    makeHeader("MODULE 03 - ex01 - Serena, my love!");
    std::cout << KNOR "-- Constructors --" << std::endl;
    ScavTrap one("Unai");
    ScavTrap two("Beñat");

    std::cout << std::endl << KNOR "-- Actions --" << std::endl;
    one.attack("Beñat");
    two.takeDamage(one.getDamage());
    std::cout << one << std::endl;
    std::cout << two << std::endl;
    one.beRepaired(2);
    std::cout << one << std::endl;
    two.takeDamage(9);
    std::cout << two << std::endl;

    std::cout << KNOR "-- New and copy --" << std::endl;
    ScavTrap *other = new ScavTrap("Elian");
    *other = one;
    std::cout << *other << std::endl;

    std::cout << KNOR "-- Default constructor --" << std::endl;
    ScavTrap three;
    std::cout << std::endl << KNOR "-- Guard Keeper --" << std::endl;
    one.guardGate();
    std::cout << KNOR "-- Destructors --" << std::endl;
    delete other;
  }
  {
    makeHeader("MODULE 03 - ex01 - Serena, my love!");
    std::cout << std::endl << KNOR "-- Demostrate ClapTrap --" << std::endl;
    std::cout << "Creating ClapTrap object:" << std::endl;
    ClapTrap claptrap("CL4P-TP");
    claptrap.attack("Bandit");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);

    std::cout << KNOR "-- Demostrate ScavTrap --" << std::endl;
    std::cout << "Creating ScavTrap object:" << std::endl;
    ScavTrap scavtrap("SC4V-TP");
    scavtrap.attack("Bandit");
    scavtrap.takeDamage(10);
    scavtrap.beRepaired(5);
    scavtrap.guardGate();
	std::cout << std::endl<< KNOR "-- Destructors --" << std::endl;
  }
}
/**
 * @brief  Function to create a header with a given text.
 *
 * @param moduleText Text of the module.
 */
void makeHeader(const std::string &moduleText)
{
  int lineLength = moduleText.length() + 2; // Adjust for extra spaces

  std::string line = std::string(lineLength, '-');
  std::cout << KBLU << line << KNOR << std::endl;
  std::cout << KBLU << " " << moduleText << " " << KNOR << std::endl;
  std::cout << KBLU << line << KNOR << std::endl;
  makeDolphin(lineLength);
  std::cout << KBLU << line << KNOR << std::endl;
}
/**
 * @brief Function to create a visual representation of a dolphin.
 *
 * @param lineLength Length of the dolphin line.
 */
void makeDolphin(int lineLength)
{

  lineLength = lineLength - 30;
  std::cout << KCYA << "            ,-._" << std::endl;
  std::cout << KCYA << "           _.-'  '--." << std::endl;
  std::cout << KCYA << "         .'      _  -`\\_" << std::endl;
  std::cout << KCYA << "        / .----.`_.'----'" << std::endl;
  std::cout << KCYA << "        ;/     `" << std::endl;
  std::cout << KCYA << "       /_;     " << std::endl;
  std::cout << KCYA << "" << std::endl;
  std::cout << KBLU << "    ._      ._      ._      ._" << std::endl;
  std::cout << KBLU << "_.-._)`\\_.-._)`\\_.-._)`\\_.-._)`\\_.-._" << std::endl;
}
