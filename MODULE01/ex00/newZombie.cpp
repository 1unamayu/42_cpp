/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 08:26:08 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/09 08:26:09 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Creates a new Zombie object with the given name.
 *
 * This function dynamically allocates memory for a new Zombie object with the provided name in the
 * HEAP.
 *
 * @param name A string representing the name of the new Zombie.
 * @return A pointer to the newly created Zombie object.
 */
Zombie *newZombie(std::string name)
{
  Zombie *new_zombie;

  new_zombie = new Zombie(name);
  return new_zombie;
}
