/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 08:03:02 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/09 08:29:10 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
  std::cout << "Creating zombie1..." << std::endl;
  std::cout << "--------------------------" << std::endl;
  Zombie *zombie1 = newZombie("Zombie1");

  std::cout << "Zombie1 announces itself:" << std::endl;
  std::cout << "--------------------------" << std::endl;
  zombie1->announce();
  std::cout << "--------------------------" << std::endl;
  std::cout << "Deleting zombie1..." << std::endl;
  delete(zombie1);
  std::cout << "--------------------------" << std::endl;
  std::cout << "Calling randomChump..." << std::endl;
  randomChump("Unai");
}