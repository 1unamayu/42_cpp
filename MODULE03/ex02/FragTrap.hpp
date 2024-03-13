/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:28:38 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/13 12:41:11 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
  FragTrap(const std::string &name);          // CONSTRUCTOR
  FragTrap(const FragTrap &other);            // COPY CONSTRUCTOR
  FragTrap &operator=(const FragTrap &other); // ASSIGMENT OPERATOR
  ~FragTrap();                                // DESTRUCTOR
  void highFivesGuy(void);                    // FRAGTRAP FUNCTION
};
#endif