/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 10:41:15 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/09 12:22:17 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
// COLORS
#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"
#define KBLA "\033[0;30m"

#include <iostream>
#include <string>

// WEAPON CLASS
class Weapon
{
private:
  std::string _type; // The type of the weapon

public:
  Weapon(std::string type); // CONSTRUCTOR WITH TYPE PARAMETER
  Weapon();                 // DEFAULT CONSTRUCTOR

  const std::string &getType(); // TYPE GETTER

  void setType(const std::string &type); // TYPE SETTER

  ~Weapon(); // DEFAULT DESTRUCTOR
};
#endif
