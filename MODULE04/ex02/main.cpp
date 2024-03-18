/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:42:17 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/18 16:25:48 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <iomanip>
#define SIZE 100
int main()
{
  //AAnimal animal;
	AAnimal *zoo[10];

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			zoo[i] = new Dog();
		else
			zoo[i] = new Cat();
	}

	for (int i = 0; i < 10; i++)
		zoo[i]->makeSound();

	for (int i = 0; i < 10; i++)
		delete zoo[i];

	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	delete j;//should not create a leak
	delete i;

	return (0);
    
}