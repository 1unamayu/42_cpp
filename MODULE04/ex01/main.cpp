/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:42:17 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/18 16:10:51 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <iomanip>
#define SIZE 100
int main()
{
  {
    std::cout << KCYA "━━━━━━━━━━━━━━━━━━" KNOR << std::endl;
    std::cout << KCYA " ARRAY OF ANIMALS " KNOR << std::endl;
    std::cout << KCYA "━━━━━━━━━━━━━━━━━━" KNOR << std::endl;

    Animal *animal_array[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
      if(i % 2 == 0)
        animal_array[i] = new Cat();
      else
        animal_array[i] = new Dog();
    }
    for(int z = 0; z < SIZE; z++)
    {
      std::cout << std::setw(3) << std::setfill('0') << z + 1 << "-"
                << animal_array[z]->getType() << " ->";
      animal_array[z]->makeSound();
    }

    for(int z = 0; z < SIZE; z++)
    {
      delete animal_array[z];
    }
  }
  {
    std::cout << KBLU "━━━━━━━━━━━" KNOR << std::endl;
    std::cout << KBLU " DEEP COPY " KNOR << std::endl;
    std::cout << KBLU "━━━━━━━━━━━" KNOR << std::endl;
    
    Dog haru;
    haru.setIdea("Vamos al parque",0);
    haru.setIdea("Quiero jugar", 1);

    Dog gohan(haru);
    gohan.setIdea("Quiero dormir",1);

    std::cout << "Haru's 1st idea: " << haru.getIdea(0) << std::endl;
    std::cout << "Haru's 1st idea: " << haru.getIdea(1) << std::endl;
    std::cout << "Gohan's 1st idea: " << gohan.getIdea(0) << std::endl;
    std::cout << "Gohan's 1st idea: " << gohan.getIdea(1) << std::endl;

    Cat covi;
    covi.setIdea("Vamos a casa",0);
    covi.setIdea("Quiero comer", 1);

    Cat shiba(covi);
    shiba.setIdea("Quiero saltar",1);

    std::cout << "Covi's 1st idea: " << covi.getIdea(0) << std::endl;
    std::cout << "Covi's 1st idea: " << covi.getIdea(1) << std::endl;
    std::cout << "Shiba's 1st idea: " << shiba.getIdea(0) << std::endl;
    std::cout << "Shiba's 1st idea: " << shiba.getIdea(1) << std::endl;

    
  }
}