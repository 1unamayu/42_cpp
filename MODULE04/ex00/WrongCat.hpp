/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:48:24 by xamayuel          #+#    #+#             */
/*   Updated: 2024/04/30 15:23:23 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

class WrongCat : public WrongAnimal
{

public:
  WrongCat();                    // DEFAULT CONSTRUCTOR
  WrongCat(WrongCat const &src); // COPY CONSTRUCTOR
  ~WrongCat();                   // DEFAULT DESTRUCTOR

  WrongCat &operator=(WrongCat const &rhs); // COPY ASSIGNMENT CONSTURCTOR
  void makeSound() const;                   // MAKE SOUND METHOD
};

std::ostream &operator<<(std::ostream &o, WrongCat const &i);

#endif
