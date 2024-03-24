/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:24:59 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/24 12:44:04 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
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