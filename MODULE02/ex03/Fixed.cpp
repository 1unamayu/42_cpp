/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:58:50 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/25 11:24:18 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// INCLUDES
#include "Fixed.hpp"

//  CONSTRUCTORS
Fixed::Fixed()
{
  std::cout << KBLA "Default constructor called" KNOR << std::endl;
  _fixed_point = 0;
}
Fixed::Fixed(const int value)
{
  std::cout << KBLA "Int constructor called" KNOR << std::endl;
  _fixed_point = value << _fractionalbits;
}
Fixed::Fixed(const Fixed &fixed)
{
  std::cout << KBLA "Copy constructor called" KNOR << std::endl;
  *this = fixed;
}
Fixed::Fixed(const float value)
{
  std::cout << KBLA "Float constructor called" KNOR << std::endl;
  _fixed_point = roundf(value * (1 << _fractionalbits));
}
// DESTRUCTOR
Fixed::~Fixed()
{
  std::cout << KBLA "Destructor called" KNOR << std::endl;
}
//  COPY ASSIGMENT OPERATOR
Fixed &Fixed::operator=(const Fixed &fixed)
{
  std::cout << KBLA "Copy assignment operator called" KNOR << std::endl;
  _fixed_point = fixed.getRawBits();
  return *this;
}
// COMPARASION OPERATORS
bool Fixed::operator>(const Fixed &other) const
{
  return _fixed_point > other._fixed_point;
}
bool Fixed::operator>=(const Fixed &other) const
{
  return _fixed_point >= other._fixed_point;
}
bool Fixed::operator<(const Fixed &other) const
{
  return _fixed_point < other._fixed_point;
}
bool Fixed::operator<=(const Fixed &other) const
{
  return _fixed_point <= other._fixed_point;
}
bool Fixed::operator==(const Fixed &other) const
{
  return _fixed_point == other._fixed_point;
}
bool Fixed::operator!=(const Fixed &other) const
{
  return _fixed_point != other._fixed_point;
}
// GETTER AND SETTER
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
// FLOAT AND INT
int Fixed::toInt(void) const
{
  return _fixed_point >> _fractionalbits;
}
float Fixed::toFloat(void) const
{
  float aux;

  aux = (float)_fixed_point / (1 << _fractionalbits);
  return aux;
}
// ARITHMETIC OPERATORS
Fixed Fixed::operator+(const Fixed &other)
{
  Fixed out;

  out.setRawBits(_fixed_point + other.getRawBits());
  return out;
}

Fixed Fixed::operator-(const Fixed &other)
{
  Fixed out;

  out.setRawBits(_fixed_point - other.getRawBits());
  return out;
}

Fixed Fixed::operator*(const Fixed &other)
{
  Fixed out;

  out.setRawBits((_fixed_point * other.getRawBits()) >> _fractionalbits);
  return out;
}
Fixed Fixed::operator/(const Fixed &other)
{
  Fixed out;

  out.setRawBits((_fixed_point << _fractionalbits) / other.getRawBits());
  return out;
}
// INCREMENT/DECREMENT FUNCTIONS
Fixed Fixed::operator+(void) const
{
  return (Fixed(*this));
}
Fixed Fixed::operator-(void) const
{
  return (Fixed(*this));
}
Fixed &Fixed::operator++(void)
{
  this->_fixed_point++;
  return (*this);
}
Fixed Fixed::operator++(int)
{
  Fixed out(*this);
  this->_fixed_point++;
  return (out);
}
Fixed &Fixed::operator--(void)
{
  this->_fixed_point--;
  return *this;
}
Fixed Fixed::operator--(int)
{
  Fixed out(*this);

  this->_fixed_point--;
  return (out);
}
// LOGIC FUNCTIONS
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
  if(b > a)
    return a;
  return b;
}
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
  if(b > a)
    return a;
  return b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
  if(b > a)
    return b;
  return a;
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
  if(b > a)
    return b;
  return a;
}
std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
  o << KBLU << fixed.toFloat();
  return o;
}
