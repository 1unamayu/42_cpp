#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>
class Dog : public AAnimal
{
private:
  Brain *_brain;

public:
  Dog();
  Dog(Dog const &src);
  ~Dog();

  Dog &operator=(Dog const &rhs);
  void makeSound() const;
  void setIdea(std::string idea, int index);
  std::string getIdea(int index);
};

std::ostream &operator<<(std::ostream &o, Dog const &i);

#endif
