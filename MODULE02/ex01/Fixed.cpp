/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:58:50 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/24 12:55:42 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// INCLUDES
#include "Fixed.hpp"

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
/**
 * @brief Default constructor of the Fixed class.
 *
 */
Fixed::Fixed()
{
    std::cout << KBLA "FIXED: Default constructor called" KNOR << std::endl;
    _fixed_point = 0;
}
/**
 * @brief Constructor to initialize with an integer value
 * @param value The integer value to be converted to fixed-point
 */
Fixed::Fixed(const int value)
{
    std::cout << KBLA "FIXED: Int constructor called" KNOR << std::endl;
    _fixed_point = value << _fractionalbits;
}
/**
 * @brief Constructor to initialize with a floating point value
 * @param value The floating point value to be converted to fixed-point
 */
Fixed::Fixed(const float value)
{
    std::cout << KBLA "FIXED:Float constructor called" KNOR << std::endl;
    _fixed_point = roundf(value * (1 << _fractionalbits));
}
/**
 * @brief Destructor of the Fixed class
 *
 */
Fixed::~Fixed()
{
    std::cout << KBLA "FIXED:Destructor called" KNOR << std::endl;
}

/**
 * @brief Overloading of the assignment operator for the Fixed class.
 *
 * @param fixed Fixed object to assign.
 * @return Fixed&
 */
Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << KBLA "FIXED:Copy assignment operator called" KNOR << std::endl;
    _fixed_point = fixed.getRawBits();
    return *this;
}
/**
 * @brief Constructor of the Fixed class for copying..
 *
 * @param fixed Fixed object to assign.
 */
Fixed::Fixed(const Fixed &fixed)
{
    std::cout << KBLA "FIXED:Copy constructor called" KNOR << std::endl;
    *this = fixed;
}
/**
 * @brief Function to obtain the value in fixed-point format.
 *
 * @return int
 */
int Fixed::getRawBits(void) const
{
    std::cout << KBLA "FIXED:getRawBits member function called" KNOR << std::endl;
    return this->_fixed_point;
}
/**
 * @brief Function to set the value in fixed-point format.
 *
 * @param raw Value to set.
 */
void Fixed::setRawBits(int const raw)
{
    std::cout << KBLA "FIXED:setRawBits member function called" KNOR << std::endl;
    _fixed_point = raw;
}

/**
 * @brief Convert the fixed-point number to an integer
 * @return The integer value of the fixed-point number
 */
int Fixed::toInt(void) const
{
    return _fixed_point >> _fractionalbits;
}
/**
 * @brief Convert the fixed-point number to a floating point number
 * @return The floating point value of the fixed-point number
 */
float Fixed::toFloat(void) const
{
    float aux;

    aux = (float)_fixed_point / (1 << _fractionalbits);
    return aux;
}
/**
 * @brief Overloaded stream insertion operator to output Fixed object
 * @param o The output stream
 * @param fixed The Fixed object to output
 * @return Reference to the output stream
 */
std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
    o << fixed.toFloat();
    return o;
}