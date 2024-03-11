/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:24:59 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/11 13:26:06 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
  int _fixed_point;           // integer to store fixed-point number
  static const int _bits = 8; // fractional bits

public:
  Fixed();                              // Default constructor
  Fixed(const Fixed &fixed);            // Copy constructor
  ~Fixed();                             // Default destructor
  Fixed &operator=(const Fixed &fixed); // copy assignment operator overload
  int getRawBits(void) const;     // function to return the fixed point value
  void setRawBits(int const raw); // function to set the fixed point value
};

#endif