#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>
#define KRED "\033[0;31m"
#define KPUR "\033[0;35m"
#define KNOR "\033[0;37m"
#define KCYA "\033[0;36m"
#define KRED "\033[0;31m"
#define KYEL "\033[0;33m"
#define KBLA "\033[0;30m"
#define KBLU "\x1B[34m"

class WrongAnimal
{

public:
  WrongAnimal();
  WrongAnimal(WrongAnimal const &src);
  ~WrongAnimal();

  WrongAnimal &operator=(WrongAnimal const &rhs);
  std::string getType() const; // GETTER
  void makeSound() const;      // METHOD MAKESOUND

protected:
  std::string type;
};

std::ostream &operator<<(std::ostream &o, WrongAnimal const &i);

#endif