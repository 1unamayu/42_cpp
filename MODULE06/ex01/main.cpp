#include "Serializer.hpp"
#include <iostream>

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
/*
reinterpret_cast<uintptr_t>(dataPtr);
Convierte el puntero dataPtr de tipo Data* a un entero sin signo de tipo
uintptr_t. Esto es útil para almacenar o transmitir punteros como valores
enteros.

reinterpret_cast<Data*>(raw);
Convierte el entero raw de vuelta a un puntero de tipo Data*.
Esto permite recuperar el puntero original a partir del valor entero.
Precauciones
Seguridad: reinterpret_cast no garantiza la seguridad de la conversión. Si se
usa incorrectamente, puede llevar a comportamientos indefinidos. Portabilidad:
Las conversiones realizadas con reinterpret_cast pueden no ser portables entre
diferentes plataformas o compiladores. Uso limitado: Debe usarse con precaución
y solo cuando sea absolutamente necesario, ya que puede hacer que el código sea
difícil de entender y mantener.
*/

void testReinterpretCast(void)
{
  Data *original = new Data;
  original->id = 42;
  original->name = "Ejemplo";

  std::cout << KBLU << "Datos originales: id = " << original->id
            << ", nombre = " << original->name << KNOR << std::endl;

  uintptr_t serialized = Serializer::serialize(original);
  Data *deserialized = Serializer::deserialize(serialized);

  std::cout << KCYA << "Datos deserializados: id = " << deserialized->id
            << ", nombre = " << deserialized->name << KNOR << std::endl;

  if(original == deserialized)
  {
    std::cout << KGRE << "La serialización y deserialización fueron exitosas."
              << KNOR << std::endl;
  }
  else
  {
    std::cout << KRED << "Error en la serialización o deserialización." << KNOR << std::endl;
  }

  
  delete original;
}
int main(void)
{
  testReinterpretCast();
  return 0;
}