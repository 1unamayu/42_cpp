#include "Serializer.hpp"

Serializer::Serializer(void)
{
  return;
}

Serializer::Serializer(Serializer const &cp)
{
  *this = cp;
}

Serializer::~Serializer(void)
{
  return;
}

Serializer &Serializer::operator=(Serializer const &src)
{
  (void)src;
  return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
  return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
  return (reinterpret_cast<Data *>(raw));
}

std::ostream &operator<<(std::ostream &o, Serializer const &rhs)
{
  (void)rhs;
  return (o);
}