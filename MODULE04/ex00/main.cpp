/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:42:17 by xamayuel          #+#    #+#             */
/*   Updated: 2024/04/23 16:48:09 by xamayuel         ###   ########.fr       */
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
  }
  {
    std::cout << KCYA "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << KNOR << std::endl;
    std::cout << KCYA "               SUBJECT TEST (OK) " KNOR << std::endl;
    std::cout << KCYA "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" KNOR << std::endl;
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
    std::cout << KRED "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" KNOR << std::endl;
    std::cout << KRED "           WRONGANIMAL TEST (LEAKS) " KNOR << std::endl;
    std::cout << KRED "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" KNOR << std::endl;

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
    std::cout << KRED "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" KNOR << std::endl;
    std::cout << KRED "           WRONGANIMAL TEST (NO POINTER) " KNOR << std::endl;
    std::cout << KRED "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" KNOR << std::endl;

    WrongAnimal w_animal;
    WrongCat w_cat;

    std::cout << w_animal.getType() << " " << std::endl;
    std::cout << w_cat.getType() << " " << std::endl;

    w_animal.makeSound();
    w_cat.makeSound();
    std::cout << KBLA << "------ CAT AND ANIMAL DELETE ---------" << std::endl;
  }
}
/**
 * @brief  Function to create a header with a given text.
 *
 * @param moduleText Text of the module.
 */
void makeHeader(const std::string &moduleText)
{
  int lineLength = moduleText.length() + 22; // Adjust for extra spaces

  std::string line = std::string(lineLength, '-');
  std::cout << KGRE << line << KNOR << std::endl;
  std::cout << KGRE << " " << moduleText << " " << KNOR << std::endl;
  std::cout << KGRE << line << KNOR << std::endl;
  makeDolphin(lineLength);
  std::cout << KGRE << line << KNOR << std::endl;
}
/**
 * @brief Function to create a visual representation of a dolphin.
 *
 * @param lineLength Length of the dolphin line.
 */
void makeDolphin(int lineLength)
{

  lineLength = lineLength +30;
  std::cout << KGRE << " " << std::endl;
  std::cout << KGRE << "                         _.--._ " << std::endl;
  std::cout << KGRE << "        .-\"|~~\"-.  ../\" __.-`\boo.. " << std::endl;
  std::cout << KGRE << "       /.  |    /\\dHHb-\" {*} _\\.-'Hboo._"
            << std::endl;
  std::cout << KGRE
            << "      |  `.|  ,'  |HHHb*_-"
               "`oHb.?HHHHHHbo."
            << std::endl;
  std::cout << KGRE << "      |_.-' ,'.--.|HP_r\"  | dP ?I_HHHHHHHHHb."
            << std::endl;
  std::cout << KGRE << "       \\_.-' f `./^'  |@_/ `=' dR.`^HHHHHHHHHb."
            << std::endl;
  std::cout << KGRE << "     ,dHPo.__|.-'    ;-\"--`-  d','    `?HHHHHHHb."
            << std::endl;
  std::cout << KGRE << "    dHHHHHHP' \\[]==--\\`--.'   /.        `?HHHHHHb"
            << std::endl;
  std::cout << KGRE << "   dHHHHHHP   _`;,    r`;.,-;./`-,__,      ?HHHHHHb"
            << std::endl;
  std::cout << KGRE << "  |HHHHHH|   |-//|    |_.'`._||      \\      |HHHHHH|"
            << std::endl;
  std::cout << KGRE << " |HHHHHH|    `.;-(,.   ,'  ,' |       |      |HHHHHH|"
            << std::endl;
  std::cout << KGRE << " |HHHHHH|       `-/  )-/`.,'   |   /|  |     |HHHHHH|"
            << std::endl;
  std::cout << KGRE
            << "|HHHHHH|          `./-/  |*}   .\\ / /  |      |HHHHHH| "
            << std::endl;
  std::cout << KGRE
            << "|HHHHHH|            /*}/ ^ "
               "{*}|    |  |       |HHHHHH| "
            << std::endl;
  std::cout << KGRE
            << "|HHHHHH|          ,' ^|       ^ |   \\  \\      |HHHHHH|"
            << std::endl;
  std::cout << KGRE << "|HHHHHH|        ,'*}  | {*}  {*} \\  |..|      |HHHHHH|"
            << std::endl;
  std::cout << KGRE << " |HHHHHH|       `r;  /.  ^   _;---; `.  \\    |HHHHHH|"
            << std::endl;
  std::cout << KGRE << " |HHHHHH|        \\ \\|{*}_,--'    /    /\"'`-._|HHHHHH|"
            << std::endl;
  std::cout << KGRE << "  |HHHHHH|        \\ V\\,'        |    ( ,'| |||HHHHH| "
            << std::endl;
  std::cout << KGRE << "   ?HHHHHHb        | _          /     \\ `|;ddHHHHP"
            << std::endl;
  std::cout << KGRE << "    ?HHHHHHb.       \\  \"-r..    |       |  LdHHHHP"
            << std::endl;
  std::cout << KGRE << "     `?HHHHHHbo.    |   |      /      ,o(  fdHHP' "
            << std::endl;
  std::cout << KGRE << "       `?HHHHHH|[\"r_\\__.|     |   _.odHH\\ jdHP'"
            << std::endl;
  std::cout << KGRE << "         `?HHHH`||__   ``    ,;oodHHHHHPj \\P'"
            << std::endl;
  std::cout << KGRE << "           `^HHH|LL|HHoo;-r-'HHHHHHHHHHPf /"
            << std::endl;
  std::cout << KGRE << "              `^|  |HHHH\\ |HHHHHHHHHHH^'( ("
            << std::endl;
  std::cout << KGRE << "                |__|P--\"; |HHHHHH^'      \\| "
            << std::endl;
  std::cout << KGRE << "                (    `-'_||\"\"            ||"
            << std::endl;
  std::cout << KGRE << "                `--..--'`\"\" " << std::endl;
}
