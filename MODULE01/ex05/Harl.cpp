/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:35:32 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/09 15:08:16 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
/**
 * @brief Constructor for the Harl class.
 */
Harl::Harl()
{
}
/**
 * @brief Destructor for the Harl class.
 */
Harl::~Harl()
{
}
/**
 * @brief Prints a debug message.
 *
 * This function prints a debug message to the console.
 */
void Harl::debug()
{
  std::cout << KCYA
      "   DEBUG:" KBLA "I love having extra bcon for my "
      "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
            << KNOR << std::endl;
}

/**
 * @brief Prints an info message.
 *
 * This function prints an info message to the console.
 */
void Harl::info()
{
  std::cout << KBLU
      "    INFO:" KBLA "I cannot believe adding extra bacon costs more money. "
      "You didn’t put enough "
      "bacon in my burger! If you did, I wouldn’t be asking for more!"
            << KNOR << std::endl;
}
/**
 * @brief Prints a warning message.
 *
 * This function prints a warning message to the console.
 */
void Harl::warning()
{
  std::cout << KYEL " WARNING:" KBLA "I think I deserve to have some extra "
                    "bacon for free. I’ve been coming for "
                    "years whereas you started working here since last month."
            << KNOR << std::endl;
}

/**
 * @brief Prints an error message.
 *
 * This function prints an error message to the console.
 */
void Harl::error()
{
  std::cout << KRED "   ERROR:" KBLA
                    "This is unacceptable! I want to speak to the manager now."
            << KNOR << std::endl;
}

/**
 * @brief Prints a message based on the specified complaint level.
 *
 * This function prints a message based on the specified complaint level.
 *
 * @param level A string representing the complaint level (DEBUG, INFO, WARNING,
 * or ERROR).
 */
void Harl::complain(std::string level)
{
  void (Harl::*functions[])() = {&Harl::debug, &Harl::info, &Harl::warning,
                                 &Harl::error};
  std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  for(int i = 0; i < 4; i++)
  {
    if(level == levels[i])
    {
      (this->*functions[i])(); // Call the appropriate function using
                               // pointer-to-member syntax
      return;
    }
  }

  std::cerr << KRED "Invalid complain level: " << KYEL << level << KNOR
            << std::endl;
}
