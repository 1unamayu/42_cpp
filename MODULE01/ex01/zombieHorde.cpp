/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 09:07:27 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/09 09:12:50 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
  Zombie *horde = new Zombie[N];
  for(int i = 0; i < N; i++)
  {
    horde[i].set_name(name);
  }
  return horde;
}
