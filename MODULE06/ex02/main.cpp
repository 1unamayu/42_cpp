#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

/*
dynamic_cast es un operador en C++ que se utiliza para convertir punteros o
referencias de una clase base a punteros o referencias de una clase derivada de
manera segura en tiempo de ejecución. Específicamente, dynamic_cast se usa
principalmente en el contexto de la herencia polimórfica (cuando hay al menos
una función virtual en la clase base). Funcionalidad de dynamic_cast

Punteros:
Si la conversión es válida, dynamic_cast devuelve un puntero del tipo de
destino. Si la conversión no es válida (es decir, el objeto apuntado no es del
tipo de destino), devuelve nullptr.

Referencias:
Si la conversión es válida, dynamic_cast devuelve una referencia del tipo de
destino. Si la conversión no es válida, lanza una excepción std::bad_cast.

*/
Base *generate()
{
  srand(time(0));
  int random = rand() % 3;
  if(random == 0)
    return new A();
  else if(random == 1)
    return new B();
  else
    return new C();
}

void identify(Base *p)
{
  if(dynamic_cast<A *>(p) != NULL)
    std::cout << "\033[1;31mA\033[0m" << std::endl; // Red
  else if(dynamic_cast<B *>(p) != NULL)
    std::cout << "\033[1;32mB\033[0m" << std::endl; // Green
  else if(dynamic_cast<C *>(p) != NULL)
    std::cout << "\033[1;34mC\033[0m" << std::endl; // Blue
  else
    std::cout << "\033[1;33mUnknown\033[0m" << std::endl; // Yellow
}

void identify(Base &p)
{
  try
  {
    (void)dynamic_cast<A &>(p);
    std::cout << "\033[1;31mA\033[0m" << std::endl; // Red
    return;
  }
  catch(...){}

  try
  {
    (void)dynamic_cast<B &>(p);
    std::cout << "\033[1;32mB\033[0m" << std::endl; // Green
    return;
  }
  catch(...){}

  try
  {
    (void)dynamic_cast<C &>(p);
    std::cout << "\033[1;34mC\033[0m" << std::endl; // Blue
    return;
  }
  catch(...){}

  std::cout << "\033[1;33mUnknown\033[0m" << std::endl; // Yellow
}

int main(void)
{
  Base *base = generate();
  std::cout << "  Identifying using pointer: ";
  identify(base);
  std::cout << "Identifying using reference: ";
  identify(*base);
  delete base;
  return 0;
}