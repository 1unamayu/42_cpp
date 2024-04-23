/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:47:39 by xamayuel          #+#    #+#             */
/*   Updated: 2024/04/23 17:41:26 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>
class Dog : public Animal
{
private:
  Brain *_brain;

public:
  Dog();
  Dog(Dog const &src);
  ~Dog();

  Dog &operator=(Dog const &rhs);
  void makeSound() const;
  Brain *getBrain(void) const;
};

std::ostream &operator<<(std::ostream &o, Dog const &i);

#endif
