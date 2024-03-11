/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:00:25 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/22 20:00:26 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
private:
  std::string _firstName;     // First name
  std::string _lastName;      // Last name
  std::string _nickname;      // Nickname
  std::string _phoneNumber;   // Phone number
  std::string _darkestSecret; // Darkest secret

public:
  Contact(void);                      // Constructor
  ~Contact(void);                     // Destructor
  void setFirstName(void);            // Set first name
  void setLastName(void);             // Set last name
  void setNickname(void);             // Set nickname
  void setPhoneNumber(void);          // Set phone number
  void setDarkestSecret(void);        // Set darkest secret
  std::string getFirstName(void);     // Get first name
  std::string getLastName(void);      // Get last name
  std::string getNickname(void);      // Get nickname
  std::string getPhoneNumber(void);   // Get phone number
  std::string getDarkestSecret(void); // Get darkest secret
  void printContact(void);            // Print contact
};

#endif