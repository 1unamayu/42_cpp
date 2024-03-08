/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:01:04 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/22 20:23:10 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"

static void displayMenu(void);

int		main(void) 
{
	PhoneBook	phoneBook;
	Contact		contact;
	std::string	input;

	
	while (1) {
        
		displayMenu();
		if (!std::getline(std::cin, input))
			break ;
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
		{
			contact.setFirstName();
			contact.setLastName();
			contact.setNickname();
			contact.setPhoneNumber();
			contact.setDarkestSecret();
			phoneBook.addContact(contact);
		}
		else if (input == "SEARCH")
			phoneBook.searchContact();
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}
static void displayMenu(void)
{
	
    std::cout << "\033[34m╔═══════════════════════════════════════════╗\033[0m" << std::endl;
    std::cout << "\033[34m║                \033[37mPHONEBOOK\033[34m                  ║ \033[0m" << std::endl;
    std::cout << "\033[34m╠═══════════════════════════════════════════╣\033[0m" << std::endl;
	std::cout << "\033[34m║           ADD | SEARCH | EXIT             ║\033[0m " << std::endl;
	std::cout << "\033[34m╚═══════════════════════════════════════════╝\033[0m" << std::endl;
	std::cout << "\033[37mEnter a command: \033[0m";
}