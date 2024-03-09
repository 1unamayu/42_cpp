/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 08:15:10 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/09 09:21:05 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

// Color codes for console output
#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"

/**
 * @brief Class representing a Zombie
 */
class Zombie
{
private:
  std::string name;

public:
  /**
   * @brief Default constructor for Zombie class
   */
  Zombie();
  /**
   * @brief Constructor for Zombie class
   * @param name The name of the zombie
   */
  Zombie(std::string name);

  /**
   * @brief Destructor for Zombie class
   */
  ~Zombie();

  /**
   * @brief Function for the zombie to announce itself
   */
  void announce();

  /**
   * @brief Function to set the name of the zombie
   * @param newName The new name for the zombie
   */
  void set_name(std::string newName);
};

/**
 * @brief Creates a horde of zombies with the same name
 * @param N The number of zombies in the horde
 * @param name The name for all zombies in the horde
 * @return A pointer to the array of zombies
 */
Zombie *zombieHorde(int N, std::string name);
#endif