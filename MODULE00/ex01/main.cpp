/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:01:04 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/12 16:55:29 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#define KRED "\033[0;31m"

static void displayMenu(void);
static void displayMenuAdd(void);

int main(void)
{
  PhoneBook phoneBook;
  Contact contact;
  std::string input;

  while(1)
  {
    displayMenu();
    if(!std::getline(std::cin, input))
      break;
    if(input == "EXIT")
      break;
    else if(input == "ADD")
    {
      displayMenuAdd();
      contact.setFirstName();
      contact.setLastName();
      contact.setNickname();
      contact.setPhoneNumber();
      contact.setDarkestSecret();
      phoneBook.addContact(contact);
    }
    else if(input == "SEARCH")
      phoneBook.searchContact();
    else
    {
      std::cout << "\033[2J\033[1;1H";
      std::cout << KRED "Invalid command" << std::endl;
    }
  }
  return (0);
}

/**
 * @brief Displays the main menu of the phonebook application.
 *
 * This function displays a formatted menu with the following options:
 *  - ADD: Used to add a new contact to the phonebook.
 *  - SEARCH: Used to search for a contact in the phonebook.
 *  - EXIT: Used to exit the phonebook application.
 *
 * The menu is displayed using ANSI escape sequences for color and formatting.
 * After displaying the menu, it prompts the user to enter a command.
 */
static void displayMenu(void)
{
  std::cout << "\033[34m╔═══════════════════════════════════════════╗\033[0m"
            << std::endl;
  std::cout << "\033[34m║                \033[37mPHONEBOOK\033[34m             "
               "     ║ \033[0m"
            << std::endl;
  std::cout << "\033[34m╠═══════════════════════════════════════════╣\033[0m"
            << std::endl;
  std::cout << "\033[34m║           ADD | SEARCH | EXIT             ║\033[0m "
            << std::endl;
  std::cout << "\033[34m╚═══════════════════════════════════════════╝\033[0m"
            << std::endl;
  std::cout << "\033[37mEnter a command: \033[0m";
}

/**
 * @brief Displays the "Add Contact" menu of the phonebook application.
 *
 * This function clears the screen and displays a formatted menu for adding a new contact.
 * The menu uses ANSI escape sequences for color and formatting.
 *
 * There are currently no options displayed in this menu. It's likely intended for future functionality 
 * related to adding a contact. 
 */
static void displayMenuAdd(void)
{
  std::cout << "\033[2J\033[1;1H";
  std::cout << "\033[34m╔═══════════════════════════════════════════╗\033[0m"
            << std::endl;
  std::cout << "\033[34m║                \033[37mPHONEBOOK\033[34m             "
               "     ║ \033[0m"
            << std::endl;
  std::cout << "\033[34m╠═══════════════════════════════════════════╣\033[0m"
            << std::endl;
  std::cout << "\033[34m║              ADD NEW CONTACT              ║\033[0m "
            << std::endl;
  std::cout << "\033[34m╚═══════════════════════════════════════════╝\033[0m"
            << std::endl;
}