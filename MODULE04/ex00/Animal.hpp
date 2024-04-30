/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:47:52 by xamayuel          #+#    #+#             */
/*   Updated: 2024/04/30 15:21:17 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

// COLORS
#define KRED "\033[0;31m"
#define KPUR "\033[0;35m"
#define KNOR "\033[0;37m"
#define KCYA "\033[0;36m"
#define KRED "\033[0;31m"
#define KYEL "\033[0;33m"
#define KBLA "\033[0;30m"
#define KBLU "\x1B[34m"
#define KGRE "\033[0;32m"
class Animal
{

public:
  Animal();                             // DEFAULTL CONSTRUCTOR
  Animal(Animal const &src);            // COPY CONSTRUCTOR
  Animal &operator=(Animal const &rhs); // COPY CONSTRUCTOR
  virtual ~Animal();                    // DESTRUCTOR

  std::string getType() const;    // GETTER
  virtual void makeSound() const; // METHOD MAKESOUND

protected:
  std::string type; // TYPE
};

std::ostream &operator<<(std::ostream &o, Animal const &i);

#endif
