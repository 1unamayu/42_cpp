/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 08:15:56 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/09 08:15:56 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name) {
  Zombie *new_zombie;

  new_zombie = new Zombie(name);
  new_zombie->announce();
  delete new_zombie;
}