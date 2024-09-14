#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>

// Definición de la excepción personalizada
class NotFoundException : public std::exception
{
public:
  const char *what() const throw();
};

// Declaración de la plantilla de función easyfind
template <typename T> typename T::iterator easyfind(T &container, int value);

#include "easyfind.tpp"

#endif // EASYFIND_HPP
