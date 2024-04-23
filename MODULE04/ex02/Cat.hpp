/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:47:31 by xamayuel          #+#    #+#             */
/*   Updated: 2024/04/23 17:40:46 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>
class Cat : public Animal
{
private:
  Brain *_brain;

public:
  Cat();               // DEFAULT CONSTRUCTOR
  Cat(Cat const &src); // COPY CONSTRUCTOR
  ~Cat();              // DEFAULT CONSTRUCTOR

  Cat &operator=(Cat const &rhs); // COPY ASSIGNMENT CONSTURCTOR
  void makeSound() const;         // MAKE SOUND METHOD
  Brain *getBrain(void) const;
};

std::ostream &operator<<(std::ostream &o, Cat const &i);

#endif
