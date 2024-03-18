#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

// COLORS
#define KRED "\033[0;31m"
#define KPUR "\033[0;35m"
#define KNOR "\033[0;37m"
#define KCYA "\033[0;36m"
#define KRED "\033[0;31m"
#define KYEL "\033[0;33m"
#define KBLA "\033[0;30m"
#define KBLU "\x1B[34m"

class AAnimal
{

public:
  
  virtual ~AAnimal();                    // DESTRUCTOR

  std::string getType() const;    // GETTER
  virtual void makeSound() const; // METHOD MAKESOUND

protected:
  std::string type; // TYPE
  AAnimal();                             // DEFAULTL CONSTRUCTOR
  AAnimal(AAnimal const &src);            // COPY CONSTRUCTOR
  AAnimal &operator=(AAnimal const &rhs); // COPY CONSTRUCTOR
};

std::ostream &operator<<(std::ostream &o, AAnimal const &i);

#endif
