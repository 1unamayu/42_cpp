#include "iter.hpp"

// Función para imprimir un string al revés
void imprimirReverso(const std::string &str)
{
  for(std::string::const_reverse_iterator it = str.rbegin(); it != str.rend();
      ++it)
  {
    std::cout << *it << " ";
  }
 
}

// Example function to be used with iter
template <typename T> void printElement(T const &element)
{
  std::cout << element << " ";
}

// Función para incrementar un elemento

void test_with_template(void)
{
  int intArray[] = {1, 2, 3, 4, 5};
  size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

  std::cout << "Int array: ";
  iter(intArray, intArrayLength, printElement);
  std::cout << std::endl;

  std::string strArray[] = {"Hello", "World", "C++!"};
  size_t strArrayLength = sizeof(strArray) / sizeof(strArray[0]);

  std::cout << "String array: ";
  iter(strArray, strArrayLength, printElement);
  std::cout << std::endl;
}

void test_with_function()
{
  std::string palabras[] = {"Hello", "World", "C++!"};
  size_t longitud = sizeof(palabras) / sizeof(palabras[0]);

  std::cout << "Reverse string array:" << std::endl;
  iter(palabras, longitud, imprimirReverso);
}

int main(void)
{
  test_with_template();
  test_with_function();

  return 0;
}