/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:47:20 by xamayuel          #+#    #+#             */
/*   Updated: 2024/04/23 16:47:21 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain()
{
  std::cout << KBLA "BRAIN:Default constructor called" KNOR << std::endl;
  for(int z = 0; z < 100; z++)
  {
    ideas[z] = "NO_IDEA";
  }
}

Brain::Brain(const Brain &src)
{
  std::cout << KBLA "BRAIN:Default constructor called" KNOR << std::endl;
  for(int i = 0; i < 100; i++)
  {
    ideas[i] = src.getIdeas(i);
  }
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
  std::cout << KBLA "BRAIN:Desstructor called" KNOR << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &Brain::operator=(Brain const &rhs)
{
  std::cout << KBLA "BRAIN:Copy assignment constructor called" KNOR
            << std::endl;
  for(int i = 0; i < 100; i++)
  {
    ideas[i] = rhs.getIdeas(i);
  }
  return *this;
}

std::ostream &operator<<(std::ostream &o, Brain const &i)
{
  for(int j = 0; j < 100; j++)
  {
    o << "Idea " << j << " = " << i.getIdeas(j) << std::endl;
  }

  return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string Brain::getIdeas(int n) const
{
  return (this->ideas[n]);
}

void Brain::setIdeas(std::string idea, int n)
{
  if(n < 0 || n > 100)
    std::cout << "error. Brain's array size is 100." << std::endl;
  else
    this->ideas[n] = idea;
}
