/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:48:04 by xamayuel          #+#    #+#             */
/*   Updated: 2024/04/23 16:48:04 by xamayuel         ###   ########.fr       */
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
  Dog();
  Dog(Dog const &src);
  ~Dog();

  Dog &operator=(Dog const &rhs);
  void makeSound() const;

private:
};

std::ostream &operator<<(std::ostream &o, Dog const &i);

#endif
