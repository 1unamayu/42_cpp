/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:42:17 by xamayuel          #+#    #+#             */
/*   Updated: 2024/04/23 15:35:39 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongCat.hpp"

int main()
{
  {
    std::cout << KCYA "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << KNOR
              << std::endl;
    std::cout << KCYA "               SUBJECT TEST (OK) " KNOR << std::endl;
    std::cout << KCYA "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" KNOR
              << std::endl;
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << KBLA << "------ ANIMAL DELETE ---------" << std::endl;
    delete meta;
    std::cout << KBLA << "------ DOG DELETE ---------" << std::endl;
    delete j;
    std::cout << KBLA << "------ CAT DELETE ---------" << std::endl;
    delete i;
  }
  {
    std::cout << KRED "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" KNOR
              << std::endl;
    std::cout << KRED "           WRONGANIMAL TEST (LEAKS) " KNOR << std::endl;
    std::cout << KRED "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" KNOR
              << std::endl;

    const WrongAnimal *w_animal = new WrongAnimal();
    const WrongAnimal *w_cat = new WrongCat();

    std::cout << w_animal->getType() << " " << std::endl;
    std::cout << w_cat->getType() << " " << std::endl;

    w_animal->makeSound();
    w_cat->makeSound(); // will not output WrongCat sound "Wrong Meow!"

    std::cout << KBLA << "------ CAT DELETE (LEAKS)---------" << std::endl;
    delete w_cat;
    std::cout << KBLA << "------ ANIMAL DELETE ---------" << std::endl;
    delete w_animal;
  }
  {
    std::cout << KRED "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" KNOR
              << std::endl;
    std::cout << KRED "           WRONGANIMAL TEST (NO POINTER) " KNOR
              << std::endl;
    std::cout << KRED "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" KNOR
              << std::endl;

    WrongAnimal w_animal;
    WrongCat w_cat;

    std::cout << w_animal.getType() << " " << std::endl;
    std::cout << w_cat.getType() << " " << std::endl;

    w_animal.makeSound();
    w_cat.makeSound();
    std::cout << KBLA << "------ CAT AND ANIMAL DELETE ---------" << std::endl;
  }
}