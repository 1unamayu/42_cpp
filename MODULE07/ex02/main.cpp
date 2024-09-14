#include "Array.hpp"
#include <iostream>

void testDefaultConstructor()
{
  Array<int> arr1;
  std::cout << "Size of arr1: " << arr1.size() << std::endl;
}

void testConstructorWithSize()
{
  Array<int> arr2(5);
  std::cout << "Size of arr2: " << arr2.size() << std::endl;
}

void testCopyConstructor()
{
  Array<int> arr2(5);
  Array<int> arr3(arr2);
  std::cout << "Size of arr3: " << arr3.size() << std::endl;
}

void testAssignmentOperator()
{
  Array<int> arr2(5);
  Array<int> arr4;
  arr4 = arr2;
  std::cout << "Size of arr4: " << arr4.size() << std::endl;
}

void testSubscriptOperatorAndException()
{
  Array<int> arr2(5);
  Array<int> arr3(arr2);
  try
  {
    arr2[0] = 10;
    std::cout << "arr2[0]: " << arr2[0] << std::endl;
    std::cout << "arr3[0]: " << arr3[0]
              << std::endl; // Should be different from arr2[0]
    std::cout << "arr2[10]: " << arr2[10]
              << std::endl; // Should throw exception
  }
  catch(const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
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

void testConStrings()
{
  Array<std::string> arrStrings(3);
  arrStrings[0] = "Hola";
  arrStrings[1] = "Mundo";
  arrStrings[2] = "C++";

  std::cout << "Tamaño del array de strings: " << arrStrings.size()
            << std::endl;
  for(unsigned int i = 0; i < arrStrings.size(); ++i)
  {
    std::cout << "arrStrings[" << i << "]: " << arrStrings[i] << std::endl;
  }

  try
  {
    std::cout << "Intentando acceder a un índice fuera de rango..."
              << std::endl;
    std::cout << arrStrings[3] << std::endl;
  }
  catch(const std::exception &e)
  {
    std::cerr << "Excepción capturada: " << e.what() << std::endl;
  }
}
int main()
{
  test_separator(
      "------------------ Test with Default Constructor ------------------");
  testDefaultConstructor();
  test_separator(
      "------------------ Test with Constructor with size ------------------");
  testConstructorWithSize();
  test_separator(
      "------------------ Test with Copy Constructor ------------------");
  testCopyConstructor();
  test_separator(
      "------------------ Test with Assignment Operator ------------------");
  testAssignmentOperator();
  test_separator("------------------ Test with Subscript Operator and "
                 "Exception ------------------");
  testSubscriptOperatorAndException();
  test_separator("------------------ Test con Strings ------------------");

  testConStrings();
  return 0;
}
