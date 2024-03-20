/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:24:59 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/20 19:59:13 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <cmath>
#include <iostream>
#include <ostream>
// COLORS
// COLORS
#define KRED "\033[0;31m"
#define KGRE "\033[0;32m"
#define KYEL "\033[0;33m"
#define LBLU "\033[0;34m"
#define KPUR "\033[0;35m"
#define KNOR "\033[0;37m"
#define KCYA "\033[0;36m"

#define KBLA "\033[0;30m"
#define KBLU "\x1B[34m"
// CLASS
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
  // COMPARASION OPERATORS
  bool operator>(const Fixed &other) const;
  bool operator>=(const Fixed &other) const;
  bool operator<(const Fixed &other) const;
  bool operator<=(const Fixed &other) const;
  bool operator==(const Fixed &other) const;
  bool operator!=(const Fixed &other) const;
  // ARITHMETIC OPERATORS
  Fixed operator+(const Fixed &other);
  Fixed operator-(const Fixed &other);
  Fixed operator*(const Fixed &other);
  Fixed operator/(const Fixed &other);
  // INCREMENT/DECREMENT FUNCTIONS
  Fixed operator+(void) const;
  Fixed operator-(void) const;
  Fixed &operator++(void);
  Fixed operator++(int);
  Fixed &operator--(void);
  Fixed operator--(int);
  // GETTER AND SETTER
  int getRawBits(void) const;     // function to return the fixed point value
  void setRawBits(int const raw); // function to set the fixed point value
  // FLOAT AND INT
  float toFloat(void) const; // Function to show number as float
  int toInt(void) const;     // Function to show number as int

  // LOGIC FUNCTIONS
  static const Fixed &min(const Fixed &a, const Fixed &b);
  static Fixed &min(Fixed &a, Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
};
std::ostream &operator<<(std::ostream &o, Fixed const &fixed);
#endif