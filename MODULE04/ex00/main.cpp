/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:42:17 by xamayuel          #+#    #+#             */
/*   Updated: 2024/04/19 17:56:27 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongCat.hpp"

void makeHeader(const std::string &moduleText);
void makeDolphin(int lineLength);

int main()
{
  {
    makeHeader("MODULE 04 - ex00 - Polymorphism");
    std::cout << KCYA "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" KNOR << std::endl;
    std::cout << KCYA "            SUBJECT TEST " KNOR << std::endl;
    std::cout << KCYA "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" KNOR << std::endl;
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
  }
  {
    std::cout << KYEL "━━━━━━━━━━━━━━━━━━" KNOR << std::endl;
    std::cout << KYEL " WRONGANIMAL TEST " KNOR << std::endl;
    std::cout << KYEL "━━━━━━━━━━━━━━━━━━" KNOR << std::endl;

    const WrongAnimal *w_animal = new WrongAnimal();
    const WrongAnimal *w_cat = new WrongCat();

    std::cout << w_animal->getType() << " " << std::endl;
    std::cout << w_cat->getType() << " " << std::endl;

    w_animal->makeSound();
    w_cat->makeSound();

    delete w_cat;
    delete w_animal;
  }
}
/**
 * @brief  Function to create a header with a given text.
 *
 * @param moduleText Text of the module.
 */
void makeHeader(const std::string &moduleText)
{
  int lineLength = moduleText.length() + 2; // Adjust for extra spaces

  std::string line = std::string(lineLength, '-');
  std::cout << KBLU << line << KNOR << std::endl;
  std::cout << KBLU << " " << moduleText << " " << KNOR << std::endl;
  std::cout << KBLU << line << KNOR << std::endl;
  makeDolphin(lineLength);
  std::cout << KBLU << line << KNOR << std::endl;
}
/**
 * @brief Function to create a visual representation of a dolphin.
 *
 * @param lineLength Length of the dolphin line.
 */
void makeDolphin(int lineLength)
{

  lineLength = lineLength - 30;
  std::cout << KCYA << "            ,-._" << std::endl;
  std::cout << KCYA << "           _.-'  '--." << std::endl;
  std::cout << KCYA << "         .'      _  -`\\_" << std::endl;
  std::cout << KCYA << "        / .----.`_.'----'" << std::endl;
  std::cout << KCYA << "        ;/     `" << std::endl;
  std::cout << KCYA << "       /_;     " << std::endl;
  std::cout << KCYA << "" << std::endl;
  std::cout << KBLU << "    ._      ._      ._      ._" << std::endl;
  std::cout << KBLU << "_.-._)`\\_.-._)`\\_.-._)`\\_.-._)`\\_.-._" << std::endl;
}
