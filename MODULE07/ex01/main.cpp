#include "iter.hpp"

// Función para imprimir un string al revés
void imprimirReverso(const std::string &str)
{
  for(std::string::const_reverse_iterator it = str.rbegin(); it != str.rend();
      ++it)
  {
    std::cout << *it ;
  }
}
void convertirMayusculas(const std::string &str)
{
  for(std::string::const_iterator it = str.begin(); it != str.end(); ++it)
  {
    std::cout << (char)std::toupper(*it);
  }
}
// Example function to be used with iter
template <typename T> void printElement(T const &element)
{
  std::cout << element;
}
template <typename T> void printElementInt  (T const &element)
{
  std::cout << element << " ";
}
// Función para incrementar un elemento

void test_with_template(void)
{
  int intArray[] = {1, 2, 3, 4, 5};
  size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);
  std::cout << "\033[36m";
  std::cout << "Int array: ";
  std::cout << "\033[0m";
  iter(intArray, intArrayLength, printElementInt);
  std::cout << std::endl;
}

void test_with_template_string()
{
  std::string strArray[] = {"Hello ", "World ", "C++!"};
  size_t strArrayLength = sizeof(strArray) / sizeof(strArray[0]);
std::cout << "\033[36m";
  std::cout << "String array: ";
  std::cout << "\033[0m";
  iter(strArray, strArrayLength, printElement);
  std::cout << std::endl;
}
void test_with_function()
{
  std::string palabras[] = {"Hello", " World ", "C++!"};
  size_t longitud = sizeof(palabras) / sizeof(palabras[0]);
  std::cout << "\033[36m";
  std::cout << "Original string array: ";
  std::cout << "\033[0m";
  iter(palabras, longitud, printElement);
  std::cout << std::endl;
  std::cout << "\033[36m";
  std::cout << "Reverse string array:  ";
  std::cout << "\033[0m";
  iter(palabras, longitud, imprimirReverso);
  std::cout << std::endl;
}
void test_with_uppercase_function()
{
  std::string palabras[] = {"hello ", "world ", "c++!"};
  size_t longitud = sizeof(palabras) / sizeof(palabras[0]);

  std::cout << "\033[36m";
  std::cout << "Original string array:  ";
  std::cout << "\033[0m";
  iter(palabras, longitud, printElement);
  std::cout << "\033[36m" << std::endl;
  std::cout << "Uppercase string array: ";
  std::cout << "\033[0m";
  iter(palabras, longitud, convertirMayusculas);
  std::cout << std::endl;
}
void test_separator(const std::string &separator) {
  std::cout << "\033[34m";
  std::string linea(120, '-');
  size_t inicio = (120 - separator.length()) / 2;
  linea.replace(inicio, separator.length(), separator);
  std::cout << linea << std::endl;
  std::cout << "\033[0m";
}
int main(void)
{
  test_separator("------------------ Test with template ------------------");

  test_with_template();
  test_separator("------------------ Test with template string ------------------");
  test_with_template_string();
  test_separator("------------------ Test with function ------------------");
  test_with_function();
  test_separator("------------------ Test with uppercase function ------------------");
  test_with_uppercase_function();
  return 0;
}