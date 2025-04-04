/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:47:58 by xamayuel          #+#    #+#             */
/*   Updated: 2024/04/30 15:21:33 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>
class Cat : public Animal
{

public:
  Cat();               // DEFAULT CONSTRUCTOR
  Cat(Cat const &src); // COPY CONSTRUCTOR
  ~Cat();              // DEFAULT DESTRUCTOR

  Cat &operator=(Cat const &rhs); // COPY ASSIGNMENT CONSTURCTOR
  void makeSound() const;         // MAKE SOUND METHOD

private:
};

std::ostream &operator<<(std::ostream &o, Cat const &i);

#endif
