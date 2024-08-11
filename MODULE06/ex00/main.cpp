/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:22:57 by xamayuel          #+#    #+#             */
/*   Updated: 2024/08/11 20:39:39 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* falta comprobar los numeros limites maximos */
int main(int argc, char **argv)
{
  if(argc != 2)
  {
    std::cout << "Error: Invalid number of arguments" << std::endl;
    return (1);
  }

  ScalarConverter::convert(argv[1]);
  return (0);
}