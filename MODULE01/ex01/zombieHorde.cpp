/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 09:07:27 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/09 09:12:50 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Creates a horde of Zombie objects with the specified name for each zombie.
 *
 * This function dynamically allocates memory for an array of Zombie objects,
 * with each zombie having a unique name based on the provided name and an index.
 *
 * @param N An integer representing the number of zombies in the horde.
 * @param name A string representing the base name for the zombies in the horde.
 * @return A pointer to the array of Zombie objects representing the horde.
 */
Zombie *zombieHorde(int N, std::string name)
{
  Zombie *horde = new Zombie[N];
  for(int i = 0; i < N; i++)
  {
    horde[i].set_name(name);
  }
  return horde;
}
