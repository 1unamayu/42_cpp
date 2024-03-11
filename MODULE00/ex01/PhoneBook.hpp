/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:01:12 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/22 20:01:13 by xamayuel         ###   ########.fr       */
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
  Contact _contacts[8];
  int _index;
  int _maxIndex;

public:
  PhoneBook(void);
  ~PhoneBook(void);
  void addContact(Contact contact);
  void searchContact(void);
  void printContacts(void);
};
#endif