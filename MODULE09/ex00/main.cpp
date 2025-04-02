
#include "BitcoinExchange.hpp"
#include <iostream>

void test_separator(const std::string &separator);
void test_subject(const std::string input);

int main(int argc, char *argv[])
{
  if(argc != 2)
    std::cerr << KRED << "Usage: ./btc <input.txt>" << KNRM << std::endl;
  else
  {
    test_separator("TEST SUBJECT");
    test_subject(argv[1]);
   
  }
}
void test_subject(const std::string input)
{
  BitcoinExchange btc;
  btc.loadData("data.csv");
  btc.readInput(input);
}
void test_separator(const std::string &separator)
{
  std::cout << "\033[34m";
  std::string linea(120, '-');
  size_t inicio = (120 - separator.length()) / 2;
  linea.replace(inicio, separator.length(), separator);
  std::cout << linea << std::endl;
  std::cout << "\033[0m";
}


