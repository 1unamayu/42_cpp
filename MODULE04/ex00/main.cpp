/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:42:17 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/18 12:18:32 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongCat.hpp"

int main()
{
  {
    std::cout << KCYA "━━━━━━━━━━━━━━" KNOR << std::endl;
    std::cout << KCYA " SUBJECT TEST " KNOR << std::endl;
    std::cout << KCYA "━━━━━━━━━━━━━━" KNOR << std::endl;
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
  
    const WrongAnimal* w_animal = new WrongAnimal();
		const WrongAnimal* w_cat = new WrongCat();

		std::cout << w_animal->getType() << " " << std::endl;
		std::cout << w_cat->getType() << " " << std::endl;

		w_animal->makeSound();
		w_cat->makeSound(); //will not output WrongCat sound "Wrong Meow!"

		delete w_cat;
		delete w_animal;
  }
}