/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:48:17 by xamayuel          #+#    #+#             */
/*   Updated: 2024/04/30 15:22:50 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>
#define KRED "\033[0;31m"
#define KPUR "\033[0;35m"
#define KNOR "\033[0;37m"
#define KCYA "\033[0;36m"
#define KRED "\033[0;31m"
#define KYEL "\033[0;33m"
#define KBLA "\033[0;30m"
#define KBLU "\x1B[34m"

class WrongAnimal
{

public:
  WrongAnimal();                       // DEFAULT CONSTRUCTOR
  WrongAnimal(WrongAnimal const &src); // COPY CONSTRUCTOR
  ~WrongAnimal();                      // DEFAULT DESTRUCTOR

  WrongAnimal &operator=(WrongAnimal const &rhs);
  std::string getType() const; // GETTER
  void makeSound() const;      // METHOD MAKESOUND

protected:
  std::string type; // TYPE
};

std::ostream &operator<<(std::ostream &o, WrongAnimal const &i);

#endif
