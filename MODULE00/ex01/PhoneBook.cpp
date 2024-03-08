/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:01:09 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/08 21:51:57 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#define KPUR "\033[0;35m"
#define KNOR "\033[0;37m"
#define KCYA "\033[0;36m"
#define KRED "\033[0;31m"

PhoneBook::PhoneBook(void) {
    this->_index = 0;
    this->_maxIndex = 0;
}

PhoneBook::~PhoneBook(void) {}

void PhoneBook::addContact(Contact contact) {
    this->_contacts[this->_index] = contact;
    std::cout << "\033[2J\033[1;1H";  // Clear the screen
    std::cout << std::endl << "Contact added successfully!" << std::endl;
    this->_index++;
    this->_maxIndex++;
    if (this->_index == 8) this->_index = 0;
    if (this->_maxIndex > 8) this->_maxIndex = 8;
}

void PhoneBook::printContacts(void) {
    int i = 0;
    if (this->_index == 0) {
        std::cout << KRED "No Contacts in PhoneBook!!!!!" KNOR << std::endl;
    }

    else {
        std::cout << "\033[2J\033[1;1H";  // Clear the screen
        std::cout
            << "\033[34m╔═══════════════════════════════════════════╗\033[0m"
            << std::endl;
        std::cout
            << "\033[34m║                \033[37mPHONEBOOK\033[34m           "
               "       ║ \033[0m"
            << std::endl;
        std::cout
            << "\033[34m╚═══════════════════════════════════════════╝\033[0m"
            << std::endl
            << std::endl;
        std::cout << KPUR "╔═══════════════════════════════════════════╗"
                  << std::endl;
        std::cout << KPUR "║   Index  ║ FirstName║  LastName║ Nickname ║"
                  << std::endl;
        std::cout << KPUR "╠═══════════════════════════════════════════╣" KNOR
                  << std::endl;
    }

    while (i < this->_maxIndex) {
        std::cout << KPUR "║        " KCYA << i + 1 << KPUR " │" KNOR;
        if (this->_contacts[i].getFirstName().length() > 10) {
            std::cout << this->_contacts[i].getFirstName().substr(0, 9) << ".";
        } else {
            std::cout << std::setw(10) << this->_contacts[i].getFirstName();
        }
        std::cout << KPUR "│" KNOR;
        if (this->_contacts[i].getLastName().length() > 10) {
            std::cout << this->_contacts[i].getLastName().substr(0, 9) << ".";
        } else {
            std::cout << std::setw(10) << this->_contacts[i].getLastName();
        }
        std::cout << KPUR "│" KNOR;
        if (this->_contacts[i].getNickname().length() > 10) {
            std::cout << this->_contacts[i].getNickname().substr(0, 9) << ".";
        } else {
            std::cout << std::setw(10) << this->_contacts[i].getNickname();
        }
        std::cout << KPUR "║" << std::endl;

        i++;
        if (i != this->_index)
            std::cout << "╠══════════│══════════│══════════│══════════╣"
                      << std::endl;
        else
            std::cout << "╚═══════════════════════════════════════════╝\033[0m"
                      << std::endl;
    }
}

void PhoneBook::searchContact(void) {
    std::string index;

    PhoneBook::printContacts();
    if (this->_index > 0) {
        std::cout << "Enter index contact to visualize: ";
        if (!std::getline(std::cin, index)) return;
        while (1) {
            if (index.length() == 1 && index[0] >= '1' && index[0] <= '8') {
                if (index[0] - '0' <= this->_maxIndex) {
                    std::cout << "\033[2J\033[1;1H";  // Clear the screen
                    this->_contacts[index[0] - '1'].printContact();
                    break;
                } else {
                    std::cout << "\033[2J\033[1;1H";  // Clear the screen
                    std::cout << KRED "Contact does not exist!" KNOR
                              << std::endl
                              << std::endl;
                    break;
                }
            } else {
                std::cout << "\033[2J\033[1;1H";  // Clear the screen
                std::cout << KRED "Invalid index!" KNOR << std::endl
                          << std::endl;
                break;
            }
        }
    }
}