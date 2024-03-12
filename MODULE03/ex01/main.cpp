/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:24:38 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/11 21:40:22 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// FALTA HACER BUEN MAIN
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
int main()
{
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