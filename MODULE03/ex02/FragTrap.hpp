/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:28:38 by xamayuel          #+#    #+#             */
/*   Updated: 2024/04/05 12:26:23 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
  FragTrap();

public:
  FragTrap(const std::string &name);          // CONSTRUCTOR
  FragTrap(const FragTrap &other);            // COPY CONSTRUCTOR
  FragTrap &operator=(const FragTrap &other); // ASSIGMENT OPERATOR
  ~FragTrap();                                // DESTRUCTOR
  void highFivesGuy(void);                    // FRAGTRAP FUNCTION
};
#endif