/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 08:15:51 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/09 09:11:28 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Default constructor for the Zombie class.
 *
 * Initializes the name of the zombie to "(null)".
 */
Zombie::Zombie()
{
  name = "(null)";
}

/**
 * @brief Constructor for the Zombie class.
 *
 * Initializes the name of the zombie to the provided name.
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

/**
 * @brief Sets the name of the zombie to the provided name.
 *
 * @param newName A string representing the new name of the zombie.
 */
void Zombie::set_name(std::string newName)
{
  this->name = newName;
}
