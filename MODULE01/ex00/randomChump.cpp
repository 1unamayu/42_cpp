/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 08:15:56 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/09 08:15:56 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Creates a new Zombie object with the given name on the heap, announces its presence, and
 * then deallocates the memory.
 *
 * This function dynamically allocates memory for a new Zombie object with the provided name on the
 * heap, announces the presence of the zombie, and then deallocates the memory before returning.
 *
 * @param name A string representing the name of the new Zombie.
 */
void randomChump(std::string name)
{
  Zombie *new_zombie;

  new_zombie = new Zombie(name);
  new_zombie->announce();
  delete new_zombie;
}
