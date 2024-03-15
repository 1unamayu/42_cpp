/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:30:33 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/09 14:42:36 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP
#include <string>

#define KRED "\033[0;31m"
#define KPUR "\033[0;35m"
#define KNOR "\033[0;37m"
#define KCYA "\033[0;36m"
#define KRED "\033[0;31m"
#define KYEL "\033[0;33m"
#define KBLA "\033[0;30m"
#define KBLU "\x1B[34m"
class Harl
{

public:
  Harl();                           // DEFAULT CONSTRUCTOR
  ~Harl();                          // DEFAULT DESTRUCTOR
  void complain(std::string level); // COMPLAIN LEVEL

private:
  void debug(void);   // DEBUG FUNCTION
  void info(void);    // INFO FUNCTION
  void warning(void); // WARNING FUNCTION
  void error(void);   // ERROR FUNCTION
};
#endif
