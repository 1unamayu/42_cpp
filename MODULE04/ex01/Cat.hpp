#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>
class Cat : public Animal
{
private:
  Brain *_brain;

public:
  Cat();               // DEFAULT CONSTRUCTOR
  Cat(Cat const &src); // COPY CONSTRUCTOR
  ~Cat();              // DEFAULT CONSTRUCTOR

  Cat &operator=(Cat const &rhs); // COPY ASSIGNMENT CONSTURCTOR
  void makeSound() const;         // MAKE SOUND METHOD
  void setIdea(std::string idea, int index);
  std::string getIdea(int index);
};

std::ostream &operator<<(std::ostream &o, Cat const &i);

#endif
