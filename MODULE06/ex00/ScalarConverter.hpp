/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:23:03 by xamayuel          #+#    #+#             */
/*   Updated: 2024/08/11 20:05:18 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

// COLORS
#define KRED "\033[0;31m"
#define KGRE "\033[0;32m"
#define KYEL "\033[0;33m"
#define LBLU "\033[0;34m"
#define KPUR "\033[0;35m"
#define KNOR "\033[0;37m"
#define KCYA "\033[0;36m"

#define KBLA "\033[0;30m"
#define KBLU "\x1B[34m"
#define SUBR "\033[0;31m\033[4m"
#define NEGR "\033[0;31m\033[1m"

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>

class ScalarConverter
{
private:
  ScalarConverter(void);
  ScalarConverter(ScalarConverter const &src);
  ~ScalarConverter(void);
  ScalarConverter &operator=(ScalarConverter const &rhs);

  static std::string _literal;
  static char _char;
  static int _int;
  static float _float;
  static double _double;
  static bool _pseudoliteral;

  static bool _isChar(std::string literal);
  static bool _isInt(std::string literal);
  static bool _isFloat(std::string literal);
  static bool _isDouble(std::string literal);
  static bool _isPseudoLiteral(const std::string literal);

  static void convertAndPrint(std::string literal, int type);
  static void printChar(double value);

public:
  static void convert(std::string literal);
  class InvalidLiteralException : public std::exception
  {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &o, ScalarConverter const &rhs);

#endif