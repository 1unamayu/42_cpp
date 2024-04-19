/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:42:17 by xamayuel          #+#    #+#             */
/*   Updated: 2024/04/19 18:43:03 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <iomanip>
#define SIZE 100

void makeHeader(const std::string &moduleText);
void makeDolphin(int lineLength);
int main()
{
  {
    makeHeader("MODULE04 - ex02 Abstract class");
    // AAnimal animal;
    AAnimal *zoo[10];

    for(int i = 0; i < 10; i++)
    {
      if(i % 2 == 0)
        zoo[i] = new Dog();
      else
        zoo[i] = new Cat();
    }

    for(int i = 0; i < 10; i++)
      zoo[i]->makeSound();

    for(int i = 0; i < 10; i++)
      delete zoo[i];

    const AAnimal *j = new Dog();
    const AAnimal *i = new Cat();

    delete j; // should not create a leak
    delete i;
  }
  {
    std::cout << KBLU
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" KNOR
              << std::endl;
    std::cout << KBLU " DEEP COPY " KNOR << std::endl;
    std::cout << KBLU
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" KNOR
              << std::endl;

    Dog haru;
    haru.setIdea("Vamos al parque", 0);
    haru.setIdea("Quiero jugar", 1);

    Dog gohan(haru);
    gohan.setIdea("Quiero dormir", 1);

    std::cout << "Haru's 1st idea: " << haru.getIdea(0) << std::endl;
    std::cout << "Haru's 2nd idea: " << haru.getIdea(1) << std::endl;
    std::cout << "Gohan's 1st idea: " << gohan.getIdea(0) << std::endl;
    std::cout << "Gohan's 2nd idea: " << gohan.getIdea(1) << std::endl;

    Cat covi;
    covi.setIdea("Vamos a Bilbao", 0);
    covi.setIdea("Quiero comer", 1);

    Cat shiba(covi);
    shiba.setIdea("Quiero saltar", 1);

    std::cout << "Covi's 1st idea: " << covi.getIdea(0) << std::endl;
    std::cout << "Covi's 2nd idea: " << covi.getIdea(1) << std::endl;
    std::cout << "Shiba's 1st idea: " << shiba.getIdea(0) << std::endl;
    std::cout << "Shiba's 2nd idea: " << shiba.getIdea(1) << std::endl;
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

  lineLength = lineLength + 30;
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
  std::cout << KGRE
            << " |HHHHHH|        \\ \\|{*}_,--'    /    /\"'`-._|HHHHHH|"
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
