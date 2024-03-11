/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:01:09 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/11 12:09:41 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#define KPUR "\033[0;35m"
#define KNOR "\033[0;37m"
#define KCYA "\033[0;36m"
#define KRED "\033[0;31m"

/**
 * @brief Constructor for the PhoneBook class.
 *
 * Initializes the index and maxIndex to 0.
 */
PhoneBook::PhoneBook(void)
{
  this->_index = 0;
  this->_maxIndex = 0;
}

/**
 * @brief Destructor for the PhoneBook class.
 */
PhoneBook::~PhoneBook(void)
{
}

/**
 * @brief Function to add a contact to the phone book.
 *
 * @param contact The contact to be added.
 *
 * Adds the contact to the _contacts array, clears the screen, and prints a
 * success message. Increments the index and maxIndex. If the index is 8, it is
 * reset to 0. If the maxIndex is greater than 8, it is set to 8.
 */
void PhoneBook::addContact(Contact contact)
{
  this->_contacts[this->_index] = contact;
  std::cout << "\033[2J\033[1;1H"; // Clear the screen
  std::cout << std::endl << "Contact added successfully!" << std::endl;
  this->_index++;
  this->_maxIndex++;
  if(this->_index == 8)
    this->_index = 0;
  if(this->_maxIndex > 8)
    this->_maxIndex = 8;
}

/**
 * @brief This function prints all the contacts in the phone book.
 *
 * If the index is 0, it prints an error message.
 * If the index is not 0, it clears the screen and displays the details of all
 * the contacts.
 *
 * @return void
 */
void PhoneBook::printContacts(void)
{
  int i = 0;
  if(this->_index == 0)
  {
    std::cout << KRED "No Contacts in PhoneBook!!!!!" KNOR << std::endl;
  }

  else
  {
    std::cout << "\033[2J\033[1;1H"; // Clear the screen
    std::cout << "\033[34m╔═══════════════════════════════════════════╗\033[0m"
              << std::endl;
    std::cout << "\033[34m║                \033[37mPHONEBOOK\033[34m           "
                 "       ║ \033[0m"
              << std::endl;
    std::cout << "\033[34m╚═══════════════════════════════════════════╝\033[0m"
              << std::endl
              << std::endl;
    std::cout << KPUR "╔═══════════════════════════════════════════╗"
              << std::endl;
    std::cout << KPUR "║   Index  ║ FirstName║  LastName║ Nickname ║"
              << std::endl;
    std::cout << KPUR "╠═══════════════════════════════════════════╣" KNOR
              << std::endl;
  }

  while(i < this->_maxIndex)
  {
    std::cout << KPUR "║        " KCYA << i + 1 << KPUR " │" KNOR;
    if(this->_contacts[i].getFirstName().length() > 10)
    {
      std::cout << this->_contacts[i].getFirstName().substr(0, 9) << ".";
    }
    else
    {
      std::cout << std::setw(10) << this->_contacts[i].getFirstName();
    }
    std::cout << KPUR "│" KNOR;
    if(this->_contacts[i].getLastName().length() > 10)
    {
      std::cout << this->_contacts[i].getLastName().substr(0, 9) << ".";
    }
    else
    {
      std::cout << std::setw(10) << this->_contacts[i].getLastName();
    }
    std::cout << KPUR "│" KNOR;
    if(this->_contacts[i].getNickname().length() > 10)
    {
      std::cout << this->_contacts[i].getNickname().substr(0, 9) << ".";
    }
    else
    {
      std::cout << std::setw(10) << this->_contacts[i].getNickname();
    }
    std::cout << KPUR "║" << std::endl;

    i++;
    if(i != this->_index)
      std::cout << "╠══════════│══════════│══════════│══════════╣" << std::endl;
    else
      std::cout << "╚═══════════════════════════════════════════╝\033[0m"
                << std::endl;
  }
}

/**
 * @brief This function is used to search for a contact in the phone book.
 *
 * It first prints all the contacts in the phone book, then prompts the user to
 * enter the index of the contact to view. If the index is valid, it clears the
 * screen and prints the contact details. If the index is not valid, it prints
 * an error message.
 *
 * @return void
 */
void PhoneBook::searchContact(void)
{
  std::string index;

  PhoneBook::printContacts();
  if(this->_index > 0)
  {
    std::cout << "Enter index contact to visualize: ";
    if(!std::getline(std::cin, index))
      return;
    while(1)
    {
      if(index.length() == 1 && index[0] >= '1' && index[0] <= '8')
      {
        if(index[0] - '0' <= this->_maxIndex)
        {
          std::cout << "\033[2J\033[1;1H";
          this->_contacts[index[0] - '1'].printContact();
          break;
        }
        else
        {
          std::cout << "\033[2J\033[1;1H";
          std::cout << KRED "Contact does not exist!" KNOR << std::endl
                    << std::endl;
          break;
        }
      }
      else
      {
        std::cout << "\033[2J\033[1;1H";
        std::cout << KRED "Invalid index!" KNOR << std::endl << std::endl;
        break;
      }
    }
  }
}