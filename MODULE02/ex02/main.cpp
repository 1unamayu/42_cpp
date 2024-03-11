/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:55:45 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/11 15:57:19 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
int main(void)
{
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));

  std::cout << KBLU << a << std::endl;
  std::cout << KBLU << ++a << std::endl;
  std::cout << KBLU << a << std::endl;
  std::cout << KBLU << a++ << std::endl;
  std::cout << KBLU << a << std::endl;

  std::cout << KCYA << b << std::endl;
  std::cout << KCYA << Fixed::max(a, b) << std::endl;
}