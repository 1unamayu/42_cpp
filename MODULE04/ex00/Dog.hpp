/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:48:04 by xamayuel          #+#    #+#             */
/*   Updated: 2024/04/30 15:22:10 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>
class Dog : public Animal
{

public:
  Dog();               // DEFAULT CONSTRUCTOR
  Dog(Dog const &src); // COPY CONSTRUCTOR
  ~Dog();              // DEFAULT DESTRUCTOR

  Dog &operator=(Dog const &rhs); // COPY ASSIGNMENT CONSTURCTOR
  void makeSound() const;         // MAKE SOUND METHOD

private:
};

std::ostream &operator<<(std::ostream &o, Dog const &i);

#endif
