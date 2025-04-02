#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

#define KRED "\x1B[31m"
#define KNRM "\x1B[0m"
#define KBLA "\033[0;30m"
class BitcoinExchange
{
private:
  std::map<std::string, float> _data;
  std::map<std::string, float> _input;

public:
  BitcoinExchange();
  ~BitcoinExchange();
  bool loadData(std::string const &csvFile);
  bool readInput(std::string const &inputFile);

private:
  bool isValideDate(const std::string &fecha);

public:
  std::string findDate(const std::string &fecha);
};
#endif