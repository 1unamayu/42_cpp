/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:54:52 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/11 11:54:55 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#define KYEL "\033[0;33m"
#define KNOR "\033[0;37m"
Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

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

std::string Contact::getFirstName(void)
{
  return (this->_firstName);
}

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

std::string Contact::getLastName(void)
{
  return this->_lastName;
}

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

std::string Contact::getNickname(void)
{
  return this->_nickname;
}

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

std::string Contact::getPhoneNumber(void)
{
  return this->_phoneNumber;
}

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

std::string Contact::getDarkestSecret(void)
{
  return this->_darkestSecret;
}

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
