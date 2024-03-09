/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 08:15:51 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/09 09:11:28 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
  name = "(null)";
}

Zombie::Zombie(std::string zombieName)
{

  name = zombieName;
}
void Zombie::announce(void)
{
  std::cout << KBLU << name << KGRN << ": BraiiiiiiinnnzzzZ..." << KNRM << std::endl;
}

Zombie::~Zombie()
{
  std::cout << KRED "Destroying zombie: " << KBLU << name << KNRM << std::endl;
}

void Zombie::set_name(std::string newName)
{
  this->name = newName;
}