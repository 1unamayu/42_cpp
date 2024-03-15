/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 08:15:10 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/09 08:52:50 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
// COLORS
#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"
// ZOMBIE CLASS
class Zombie
{
private:
  std::string name; // private attribute name

public:
  Zombie(std::string zombieName); // Constructor
  ~Zombie();                      // Destructor

  void announce();
};

Zombie *newZombie(std::string name); // newZombie function
void randomChump(std::string name);  // randomChump function
#endif
