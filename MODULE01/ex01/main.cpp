/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 08:03:02 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/09 09:06:05 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
  Zombie *horde;
  int count;
  std::cout << "Enter the number of zombies in the horde: ";
  std::cin >> count;

  horde = zombieHorde(count, "monster");

  for(int i = 0; i < count; i++)
  {
    std::cout << i + 1 << " --->";
    horde[i].announce();
  }
  delete[] horde;

  return (0);
}
