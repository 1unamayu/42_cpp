/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:31:36 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/22 18:46:55 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>


int main() {
    std::string userInput;
    std::cout << "Please enter your input: ";
    while (std::getline(std::cin, userInput))
   {
        if (userInput == "EXIT")
            break;
        if (userInput == "ADD")
            break;
        if (userInput == "SEARCH")
            break;
        std::cout << "Please enter your input: ";
   }
    return 0;
}
