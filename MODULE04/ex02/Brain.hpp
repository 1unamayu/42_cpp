/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:47:24 by xamayuel          #+#    #+#             */
/*   Updated: 2024/04/23 16:47:25 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
// COLORS
#define KRED "\033[0;31m"
#define KPUR "\033[0;35m"
#define KNOR "\033[0;37m"
#define KCYA "\033[0;36m"
#define KRED "\033[0;31m"
#define KYEL "\033[0;33m"
#define KBLA "\033[0;30m"
#define KBLU "\x1B[34m"
class Brain
{

public:
  Brain();
  Brain(Brain const &src);
  ~Brain();
  Brain &operator=(Brain const &rhs);

public: // setters and getters
  std::string getIdeas(int n) const;
  void setIdeas(std::string idea, int n);

private:
  std::string ideas[100];
};

std::ostream &operator<<(std::ostream &o, Brain const &i);

#endif
