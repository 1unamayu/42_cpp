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
  Zombie(); // DEFAULT CONSTRUCTOR

  Zombie(std::string name); // NAME CONSTRUCTOR

  ~Zombie(); // DESTRUCTOR

  void announce(); // ANNOUNCE FUNCTION

  void set_name(std::string newName); // NAME SETTER
};

Zombie *zombieHorde(int N, std::string name); // HORDE FUNCTION
#endif
