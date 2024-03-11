/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:24:59 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/11 14:09:03 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <cmath>
#include <iostream>
#include <ostream>
class Fixed
{
private:
  int _fixed_point;           // integer to store fixed-point number
  static const int _bits = 8; // fractional bits

public:
  Fixed();                              // Default constructor
  Fixed(const Fixed &fixed);            // Copy constructor
  Fixed(const int value);               // Constant integer constructor
  Fixed(const float value);             // Constant float constructor
  ~Fixed();                             // Default destructor
  Fixed &operator=(const Fixed &fixed); // copy assignment operator overload
  int getRawBits(void) const;     // function to return the fixed point value
  void setRawBits(int const raw); // function to set the fixed point value
  float toFloat(void) const;      // Function to show number as float
  int toInt(void) const;          // Function to show number as int
};
std::ostream &operator<<(std::ostream &o, Fixed const &fixed);
#endif