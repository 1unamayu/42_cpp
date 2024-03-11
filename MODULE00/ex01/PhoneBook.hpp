/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:01:12 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/11 12:14:02 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include <iostream>

#include "Contact.hpp"

class PhoneBook
{
private:
  Contact _contacts[8]; // Array to store contact information.
  int _index;    // Index of the next available slot in the _contacts array
  int _maxIndex; // Maximum capacity of the phone book

public:
  PhoneBook(void);                  // Default constructor
  ~PhoneBook(void);                 // Destructor
  void addContact(Contact contact); // Adds a contact to the phone book.
  void searchContact(void);         // Searches for a contact in the phone book
  void printContacts(void); // Prints the contact information of all entries
};
#endif