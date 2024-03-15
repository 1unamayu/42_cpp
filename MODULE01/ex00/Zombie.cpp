/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 08:15:51 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/09 08:40:16 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Constructor for the Zombie class.
 *
 * @param zombieName A string representing the name of the zombie.
 */
Zombie::Zombie(std::string zombieName)
{

  name = zombieName;
}
/**
 * @brief Announces the zombie's presence by printing a message to the console.
 *
 * This function prints the name of the zombie followed by a characteristic zombie sound.
 */
void Zombie::announce(void)
{
  std::cout << KBLU << name << KGRN << ": BraiiiiiiinnnzzzZ..." << KNRM << std::endl;
}
/**
 * @brief Destructor for the Zombie class.
 *
 * This destructor prints a message indicating the destruction of the zombie object.
 */
Zombie::~Zombie()
{
  std::cout << KRED "Destroying zombie: " << KBLU << name << KNRM << std::endl;
}
