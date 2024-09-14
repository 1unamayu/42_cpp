#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include "stdint.h"

class Serializer
{
public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);

private:
  Serializer(void);
  Serializer(Serializer const &cp);
  ~Serializer(void);
  Serializer &operator=(Serializer const &src);
};

std::ostream &operator<<(std::ostream &o, Serializer const &rhs);
#endif
