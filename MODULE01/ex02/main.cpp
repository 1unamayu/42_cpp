/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 09:27:12 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/09 09:43:38 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#define KRED "\033[0;31m"
#define KPUR "\033[0;35m"
#define KNOR "\033[0;37m"
#define KCYA "\033[0;36m"
#define KRED "\033[0;31m"
int main()
{
  // A string variable initialized to "HI THIS IS BRAIN"
  std::string str = "HI ";

  // Pointer to the string
  std::string *stringPTR = &str;

  // Reference to the string
  std::string &stringREF = str;

  // Print memory addresses
  std::cout <<  std::endl;
  std::cout << KRED "----------PRINTING MEMORY ADDRESSES-------------------" << std::endl;
  std::cout << "------------------------------------------------------" << std::endl;
  std::cout << KCYA " Memory address of the string variable: " << &str << std::endl;
  std::cout << "      Memory address held by stringPTR: " << stringPTR << std::endl;
  std::cout << "      Memory address held by stringREF: " << &stringREF << std::endl << std::endl;

  // Print values
  std::cout << KRED "-----------------PRINTING VALUES---------------------" << std::endl;
  std::cout << "------------------------------------------------------" << std::endl;
  std::cout << KCYA "        Value of the string variable: " << str << std::endl;
  std::cout << "       Value pointed to by stringPTR: " << *stringPTR << std::endl;
  std::cout << "       Value pointed to by stringREF: " << stringREF << std::endl << std::endl;

  str = "HI THIS ";
  // Print memory addresses
  std::cout <<  std::endl;
  std::cout << KRED "----------PRINTING MEMORY ADDRESSES-------------------" << std::endl;
  std::cout << "------------------------------------------------------" << std::endl;
  std::cout << KCYA " Memory address of the string variable: " << &str << std::endl;
  std::cout << "      Memory address held by stringPTR: " << stringPTR << std::endl;
  std::cout << "      Memory address held by stringREF: " << &stringREF << std::endl << std::endl;

  // Print values
  std::cout << KRED "-----------------PRINTING VALUES---------------------" << std::endl;
  std::cout << "------------------------------------------------------" << std::endl;
  std::cout << KCYA "        Value of the string variable: " << str << std::endl;
  std::cout << "       Value pointed to by stringPTR: " << *stringPTR << std::endl;
  std::cout << "       Value pointed to by stringREF: " << stringREF << std::endl << std::endl;

  stringREF = "HI THIS IS";
  // Print memory addresses
  std::cout <<  std::endl;
  std::cout << KRED "----------PRINTING MEMORY ADDRESSES-------------------" << std::endl;
  std::cout << "------------------------------------------------------" << std::endl;
  std::cout << KCYA " Memory address of the string variable: " << &str << std::endl;
  std::cout << "      Memory address held by stringPTR: " << stringPTR << std::endl;
  std::cout << "      Memory address held by stringREF: " << &stringREF << std::endl << std::endl;

  // Print values
  std::cout << KRED "-----------------PRINTING VALUES---------------------" << std::endl;
  std::cout << "------------------------------------------------------" << std::endl;
  std::cout << KCYA "        Value of the string variable: " << str << std::endl;
  std::cout << "       Value pointed to by stringPTR: " << *stringPTR << std::endl;
  std::cout << "       Value pointed to by stringREF: " << stringREF << std::endl << std::endl;

  *stringPTR = "HI THIS IS BRAIN";
  // Print memory addresses
  std::cout <<  std::endl;
  std::cout << KRED "----------PRINTING MEMORY ADDRESSES-------------------" << std::endl;
  std::cout << "------------------------------------------------------" << std::endl;
  std::cout << KCYA " Memory address of the string variable: " << &str << std::endl;
  std::cout << "      Memory address held by stringPTR: " << stringPTR << std::endl;
  std::cout << "      Memory address held by stringREF: " << &stringREF << std::endl << std::endl;

  // Print values
  std::cout << KRED "-----------------PRINTING VALUES---------------------" << std::endl;
  std::cout << "------------------------------------------------------" << std::endl;
  std::cout << KCYA "        Value of the string variable: " << str << std::endl;
  std::cout << "       Value pointed to by stringPTR: " << *stringPTR << std::endl;
  std::cout << "       Value pointed to by stringREF: " << stringREF << std::endl << std::endl;
  return 0;
}