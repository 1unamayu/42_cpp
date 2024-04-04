/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:15:14 by xamayuel          #+#    #+#             */
/*   Updated: 2024/04/04 12:28:57 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
// INCLUDES
#include <iostream>
// COLORS
// COLORS
#define KRED "\033[0;31m"
#define KGRE "\033[0;32m"
#define KYEL "\033[0;33m"
#define LBLU "\033[0;34m"
#define KPUR "\033[0;35m"
#define KNOR "\033[0;37m"
#define KCYA "\033[0;36m"

#define KBLA "\033[0;30m"
#define KBLU "\x1B[34m"
// CLASS
class ClapTrap
{
private:
  std::string _name;
  unsigned int _hitpoints;
  unsigned int _energy;
  unsigned int _attackdamage;

public:
  ClapTrap(std::string name);    // CONSTRUCTOR
  ClapTrap(ClapTrap const &src); // COPY CONSTRUCTOR
  ~ClapTrap();                   // DESTRUCTOR
  // GETTER ANS SETTER
  std::string getName(void) const;
  int getHit(void) const;
  int getEnergy(void) const;
  int getDamage(void) const;
  // OPERATOR
  ClapTrap &operator=(ClapTrap const &rhs); // OPERATOR
  // REALISTIC FUNCTIONS
  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};
std::ostream &operator<<(std::ostream &o, ClapTrap const &i);
#endif