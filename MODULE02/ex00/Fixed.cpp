/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:58:50 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/11 13:33:33 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// INCLUDES
#include "Fixed.hpp"
#include <iostream>
// COLORS
#define KRED "\033[0;31m"
#define KPUR "\033[0;35m"
#define KNOR "\033[0;37m"
#define KCYA "\033[0;36m"
#define KRED "\033[0;31m"
#define KYEL "\033[0;33m"
#define KBLA "\033[0;30m"
#define KBLU "\x1B[34m"
// CLASS FUNCTIONS
Fixed::Fixed()
{
  std::cout << KBLA "Default constructor called" KNOR << std::endl;
  _fixed_point = 0;
}

Fixed::~Fixed()
{
  std::cout << KBLA "Destructor called" KNOR << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
  std::cout << KBLA "Copy assignment operator called" KNOR << std::endl;
  _fixed_point = fixed.getRawBits();
  return *this;
}
Fixed::Fixed(const Fixed &fixed)
{
  std::cout << KBLA "Copy constructor called" KNOR << std::endl;
  *this = fixed;
}

int Fixed::getRawBits(void) const
{
  std::cout << KBLA "getRawBits member function called" KNOR << std::endl;
  return this->_fixed_point;
}

void Fixed::setRawBits(int const raw)
{
  std::cout << KBLA "setRawBits member function called" KNOR << std::endl;
  _fixed_point = raw;
}