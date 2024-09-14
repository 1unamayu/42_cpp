#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include <algorithm>

// Implementación de la excepción personalizada
const char* NotFoundException::what() const throw() {
    return "Element not found";
}

// Implementación de la plantilla de función easyfind
template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw NotFoundException();
    }
    return it;
}

#endif // EASYFIND_TPP
