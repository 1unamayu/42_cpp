/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:48:24 by xamayuel          #+#    #+#             */
/*   Updated: 2024/04/23 16:48:24 by xamayuel         ###   ########.fr       */
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
  WrongCat();
  WrongCat(WrongCat const &src);
  ~WrongCat();

  WrongCat &operator=(WrongCat const &rhs);
  void makeSound() const;
};

std::ostream &operator<<(std::ostream &o, WrongCat const &i);

#endif
