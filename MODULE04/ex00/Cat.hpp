#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>
class Cat : public Animal
{

public:
  Cat();               // DEFAULT CONSTRUCTOR
  Cat(Cat const &src); // COPY CONSTRUCTOR
  ~Cat();              // DEFAULT CONSTRUCTOR

  Cat &operator=(Cat const &rhs); // COPY ASSIGNMENT CONSTURCTOR
  void makeSound() const;         // MAKE SOUND METHOD

private:
};

std::ostream &operator<<(std::ostream &o, Cat const &i);

#endif
