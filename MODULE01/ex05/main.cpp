/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:59:46 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/09 15:07:27 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
int main()
{
  Harl miharl;

  std::cout << "Testing INFO" << std::endl;
  std::cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-" << std::endl;
  miharl.complain("INFO");
  std::cout << "Testing WARNING" << std::endl;
  std::cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-" << std::endl;
  miharl.complain("WARNING");
  std::cout << "Testing DEBUG" << std::endl;
  std::cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-" << std::endl;
  miharl.complain("DEBUG");
  std::cout << "Testing ERROR" << std::endl;
  std::cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-" << std::endl;
  miharl.complain("ERROR");
  std::cout << "Testing NO LEVEL" << std::endl;
  std::cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-" << std::endl;
  miharl.complain("OTHER");
}