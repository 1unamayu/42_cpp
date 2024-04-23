/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:42:17 by xamayuel          #+#    #+#             */
/*   Updated: 2024/04/23 17:50:57 by xamayuel         ###   ########.fr       */
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
    makeHeader("MODULE 04 - ex01 - I don't want to set the world on fire");
  }
  {
    std::cout << KCYA "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
              << KNOR << std::endl;
    std::cout << KCYA "               SUBJECT TEST (OK) " KNOR << std::endl;
    std::cout << KCYA "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
              << KNOR << std::endl;
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    delete j;
    delete i;
  }
  {
    std::cout << KCYA "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
              << KNOR << std::endl;
    std::cout << KCYA "               ARRAY TEST  " KNOR << std::endl;
    std::cout << KCYA "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
              << KNOR << std::endl;
    std::string str;
    Animal *meta[10];

    for(int i = 0; i < 10; i++)
    {
      if(i % 2)
      {
        meta[i] = new Dog();
      }
      else
      {
        meta[i] = new Cat();
      }
    }
    std::cout << std::endl;

    for(size_t i = 0; i < 10; i++)
    {
      delete meta[i];
    }
    std::cout << std::endl;
  }
  {
    std::cout << KCYA "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
              << KNOR << std::endl;
    std::cout << KCYA "               DEEP COPY TEST  " KNOR << std::endl;
    std::cout << KCYA "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
              << KNOR << std::endl;
	
	std::string str;
	Dog *d = new Dog();
	Dog *d2 = new Dog();
	std::cout << std::endl;
	str = d->getBrain()->getIdeas(0);
	std::cout << "Dog1's first idea is "<< str << std::endl;

	d->getBrain()->setIdeas("Vamos al parque", 0);
	str = d->getBrain()->getIdeas(0);
	std::cout << "Dog1's first idea is "<< str << std::endl;

	*d2 = *d;
	str = d2->getBrain()->getIdeas(0);
	std::cout << "Dog2's first idea is "<< str << std::endl;

	std::cout << std::endl;
	delete d;
	d = NULL;
	delete d2;
	d2 = NULL;
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
    haru.getBrain()->setIdeas("Vamos al parque", 0);
    haru.getBrain()->setIdeas("Quiero jugar", 1);

    Dog gohan(haru);
    gohan.getBrain()->setIdeas("Quiero dormir", 1);

    std::cout << "Haru's 1st idea: " << haru.getBrain()->getIdeas(0) << std::endl;
    std::cout << "Haru's 2nd idea: " << haru.getBrain()->getIdeas(1) << std::endl;
    std::cout << "Gohan's 1st idea: " << gohan.getBrain()->getIdeas(0) << std::endl;
    std::cout << "Gohan's 2nd idea: " << gohan.getBrain()->getIdeas(1) << std::endl;

    Cat covi;
    covi.getBrain()->setIdeas("Vamos a Bilbao", 0);
    covi.getBrain()->setIdeas("Quiero comer", 1);

    Cat shiba(covi);
    shiba.getBrain()->setIdeas("Quiero saltar", 1);

    std::cout << "Covi's 1st idea: " << covi.getBrain()->getIdeas(0) << std::endl;
    std::cout << "Covi's 2nd idea: " << covi.getBrain()->getIdeas(1) << std::endl;
    std::cout << "Shiba's 1st idea: " << shiba.getBrain()->getIdeas(0) << std::endl;
    std::cout << "Shiba's 2nd idea: " << shiba.getBrain()->getIdeas(1) << std::endl;
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
