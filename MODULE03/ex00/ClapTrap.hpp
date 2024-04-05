/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:15:14 by xamayuel          #+#    #+#             */
/*   Updated: 2024/04/05 11:44:00 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
// INCLUDES
#include <climits> // UINT_MAX
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
  ClapTrap();                               // DEFAULT CONSTRUCTOR
  ClapTrap(std::string name);               // CONSTRUCTOR
  ClapTrap(ClapTrap const &src);            // COPY CONSTRUCTOR
  ClapTrap &operator=(ClapTrap const &rhs); // OPERATOR
  ~ClapTrap();                              // DESTRUCTOR
public:                                     // GETTER ANS SETTER
  std::string getName(void) const;          // NAME GETTER
  int getHit(void) const;                   // HIT GETTER
  int getEnergy(void) const;                // ENERGY GETTER
  int getDamage(void) const;                // DAMAGE GETTER

public:                                   // FUNCTIONS
  void attack(const std::string &target); // ATTACK FUNCTION
  void takeDamage(unsigned int amount);   // TAKE DAMAGE FUNCTION
  void beRepaired(unsigned int amount);   // BE REPAIRED FUNCTION
};
std::ostream &operator<<(std::ostream &o, ClapTrap const &i);
#endif