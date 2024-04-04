/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:24:38 by xamayuel          #+#    #+#             */
/*   Updated: 2024/04/04 12:55:37 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// FALTA HACER BUEN MAIN
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
void makeHeader(const std::string &moduleText);
void makeDolphin(int lineLength);
int main()
{
	makeHeader("MODULE 03 - ex01 - Serena, my love!");
  ClapTrap one("Unai");
  ClapTrap two("Beñat");

  one.attack("Beñat");
  two.takeDamage(one.getDamage());

  std::cout << one << std::endl;
  std::cout << two << std::endl;

  ClapTrap *other = new ClapTrap("Elian");
  *other = one;
  std::cout << *other << std::endl;
  delete other;

  ScavTrap mio("haru");
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
