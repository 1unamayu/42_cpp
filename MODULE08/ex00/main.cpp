#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

void test_separator(const std::string &separator);
void testEasyFind_1(void);
void testEasyFind_2(void);

int main()
{
  test_separator(
      "------------------ Test easyfind with int vector ------------------");
  testEasyFind_1();
  test_separator(
      "------------------ Test easyfind with char vector ------------------");
  testEasyFind_2();


  return 0;
}
void testEasyFind_1()
{
  std::vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  vec.push_back(5);

  std::cout << "Contenido del vector: ";
  for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  try
  {
    std::cout << "\033[33mBuscando 3...\033[0m" << std::endl;
    std::vector<int>::iterator result = easyfind(vec, 1);
    std::cout << "\033[32mElemento 3 encontrado en la posición: "
              << (result - vec.begin()) + 1 << "\033[0m" << std::endl;
  }
  catch(const NotFoundException &e)
  {
    std::cout << "\033[31m" << e.what() << "\033[0m" << std::endl;
  }

  try
  {
    std::cout << "\033[33mBuscando 10...\033[0m" << std::endl;
    std::vector<int>::iterator result = easyfind(vec, 10);
    std::cout << "\033[32mElemento 10 encontrado en la posición: "
              << (result - vec.begin()) + 1 << "\033[0m" << std::endl;
  }
  catch(const NotFoundException &e)
  {
    std::cout << "\033[31m" << e.what() << "\033[0m" << std::endl;
  }
}

void testEasyFind_2()
{
  std::list<char> lst;
  lst.push_back('a');
  lst.push_back('b');
  lst.push_back('c');
  lst.push_back('d');
  lst.push_back('e');

  std::cout << "Contenido de la lista: ";
  for(std::list<char>::iterator it = lst.begin(); it != lst.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  try
  {
    std::cout << "\033[33mBuscando 'c'...\033[0m" << std::endl;
    std::list<char>::iterator result = easyfind(lst, 'c');
    std::cout << "\033[32mElemento 'c' encontrado en la posición: "
              << std::distance(lst.begin(), result) + 1 << "\033[0m" << std::endl;
  }
  catch(const NotFoundException &e)
  {
    std::cout << "\033[31m" << e.what() << "\033[0m" << std::endl;
  }

  try
  {
    std::cout << "\033[33mBuscando 'f'...\033[0m" << std::endl;
    std::list<char>::iterator result = easyfind(lst, 'f');
    std::cout << "\033[32mElemento 'f' encontrado en la posición: "
              << std::distance(lst.begin(), result) << "\033[0m" << std::endl;
  }
  catch(const NotFoundException &e)
  {
    std::cout << "\033[31m" << e.what() << "\033[0m" << std::endl;
  }
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
