/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:54:52 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/11 12:21:36 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#define KYEL "\033[0;33m"
#define KNOR "\033[0;37m"

/**
 * @brief Default constructor for Contact objects.
 *
 * This constructor initializes a Contact object with empty strings for
 * first name, last name, nickname, phone number, and darkest secret.
 */
Contact::Contact(void)
{
}
/**
 * @brief Destructor for Contact objects.
 *
 * (Optional) Performs any necessary cleanup when a Contact object goes
 * out of scope. In this basic implementation, no specific cleanup is
 * required.
 */
Contact::~Contact(void)
{
}
/**
 * @brief Checks if a string contains only digits (0-9).
 *
 * This function iterates through each character in the provided string
 * and checks if it is a digit using `std::isdigit`. If any character
 * is not a digit, the function returns 0. Otherwise, it returns 1
 * indicating all characters are digits.
 *
 * @param str The string to be checked.
 * @return 1 if all characters are digits, 0 otherwise.
 */
int is_digit(std::string str)
{
  int i = 0;
  while(str[i])
  {
    if(!std::isdigit(str[i]))
      return (0);
    i++;
  }
  return (1);
}
/**
 * @brief Prompts the user to enter a first name for the contact.
 *
 * This function displays a prompt asking for the first name. It uses
 * a loop to ensure a non-empty string is entered. If an empty string
 * is entered, an error message is displayed and the loop continues.
 * Once a valid non-empty string is provided, it is stored in the
 * `_firstName` member variable.
 */
void Contact::setFirstName(void)
{
  std::string firstName;

  while(1)
  {
    std::cout << "\033[0;32m    Enter first name: \033[0;37m";
    if(!std::getline(std::cin, firstName))
      break;
    if(firstName.length() > 0)
    {
      this->_firstName = firstName;
      break;
    }
    std::cout << "\033[0;31mFirst name cannot be empty.\033[0;37m" << std::endl;
  }
}
/**
 * @brief Returns the first name of the contact.
 *
 * This function simply returns the value stored in the `_firstName`
 * member variable.
 *
 * @return The first name of the contact as a string.
 */
std::string Contact::getFirstName(void)
{
  return (this->_firstName);
}
/**
 * @brief Prompts the user to enter a last name for the contact.
 *
 * This function behaves similarly to `setFirstName`. It displays a prompt
 * asking for the last name, uses a loop to ensure a non-empty string is
 * entered, and stores the valid input in the `_lastName` member variable.
 */
void Contact::setLastName(void)
{
  std::string lastName;

  while(1)
  {
    std::cout << "\033[0;32m     Enter last name: \033[0;37m";
    if(!std::getline(std::cin, lastName))
      break;
    if(lastName.length() > 0)
    {
      this->_lastName = lastName;
      break;
    }
    std::cout << "\033[0;31mLast name cannot be empty.\033[0;37m" << std::endl;
  }
}
/**
 * @brief Returns the last name of the contact.
 *
 * This function simply returns the value stored in the `_lastName` member
 * variable.
 */
std::string Contact::getLastName(void)
{
  return this->_lastName;
}

/**
 * @brief Prompts the user to enter a nickname for the contact.
 *
 * This function follows the same logic as `setFirstName` and `setLastName`.
 * It asks for the nickname, validates for a non-empty string, and stores
 * the input in the `_nickname` member variable.
 */
void Contact::setNickname(void)
{
  std::string nickname;

  while(1)
  {
    std::cout << "\033[0;32m      Enter nickname: \033[0;37m";
    if(!std::getline(std::cin, nickname))
      break;
    if(nickname.length() > 0)
    {
      this->_nickname = nickname;
      break;
    }
    std::cout << "\033[0;31mNickname cannot be empty.\033[0;37m" << std::endl;
  }
}
/**
 * @brief Returns the nickname of the contact.
 *
 * This function simply returns the value stored in the `_nickname` member
 * variable.
 */
std::string Contact::getNickname(void)
{
  return this->_nickname;
}
/**
 * @brief Prompts the user to enter a phone number for the contact.
 *
 * This function is similar to the previous setter functions. It asks for
 * the phone number, validates for a non-empty string, and stores the input
 * in the `_phoneNumber` member variable.
 */
void Contact::setPhoneNumber(void)
{
  std::string phoneNumber;

  while(1)
  {
    std::cout << "\033[0;32m  Enter phone number: \033[0;37m";
    if(!std::getline(std::cin, phoneNumber))
      break;
    if(phoneNumber.length() > 0)
    {
      this->_phoneNumber = phoneNumber;
      break;
    }
    else
      std::cout << "\033[0;31mPhone number cannot be empty.\033[0;37m"
                << std::endl;
  }
}
/**
 * @brief Returns the phone number of the contact.
 *
 * This function simply returns the value stored in the `_phoneNumber` member
 * variable.
 */
std::string Contact::getPhoneNumber(void)
{
  return this->_phoneNumber;
}
/**
 * @brief Prompts the user to enter a darkest secret for the contact.
 * (**Note:** This field might be intended for illustrative purposes only
 * and you may not want to collect such sensitive information in a real
 * application.)
 *
 * This function asks the user to enter a darkest secret (with a hint of humor).
 * It validates for a non-empty string and stores the input in the
 * `_darkestSecret` member variable.
 */
void Contact::setDarkestSecret(void)
{
  std::string darkestSecret;

  while(1)
  {
    std::cout << "\033[0;32mEnter darkest secret: \033[0;37m";
    if(!std::getline(std::cin, darkestSecret))
      break;
    if(darkestSecret.length() > 0)
    {
      this->_darkestSecret = darkestSecret;
      break;
    }
    std::cout << "\033[0;31mDarkest secret cannot be empty.\033[0;37m"
              << std::endl;
  }
}
/**
 * @brief Returns the darkest secret of the contact.
 * (**Note:** This field might be intended for illustrative purposes only
 * and you may not want to retrieve such sensitive information in a real
 * application.)
 *
 * This function simply returns the value stored in the `_darkestSecret` member
 * variable.
 */
std::string Contact::getDarkestSecret(void)
{
  return this->_darkestSecret;
}
/**
 * @brief Displays a visual menu for the contact information.
 *
 * This function is likely used for a text-based user interface. It clears the
 * screen and displays a formatted box with the title "PHONEBOOK" and "CONTACT"
 * centered.
 */
static void displayMenuVisualize(void)
{
  std::cout << "\033[2J\033[1;1H"; // Clear the screen
  std::cout << "\033[34m╔═══════════════════════════════════════════╗\033[0m"
            << std::endl;
  std::cout << "\033[34m║                \033[37mPHONEBOOK\033[34m             "
               "     ║ \033[0m"
            << std::endl;
  std::cout << "\033[34m╠═══════════════════════════════════════════╣\033[0m"
            << std::endl;
  std::cout << "\033[34m║                  CONTACT                  ║\033[0m "
            << std::endl;
  std::cout << "\033[34m╚═══════════════════════════════════════════╝\033[0m"
            << std::endl;
}
/**
 * @brief Prints the contact information in a formatted way.
 *
 * This function likely uses a text-based user interface. It calls
 * `displayMenuVisualize` to display the menu box and then prints the contact's
 * first name, last name, nickname, phone number, and darkest secret (with
 * appropriate labels) using color codes (which might need to be adjusted for
 * wider compatibility).
 */
void Contact::printContact(void)
{
  displayMenuVisualize();
  std::cout << KYEL "    First name: " KNOR << this->_firstName << std::endl;
  std::cout << KYEL "     Last name: " KNOR << this->_lastName << std::endl;
  std::cout << KYEL "      Nickname: " KNOR << this->_nickname << std::endl;
  std::cout << KYEL "  Phone number: " KNOR << this->_phoneNumber << std::endl;
  std::cout << KYEL "Darkest secret: " KNOR << this->_darkestSecret
            << std::endl;
}
