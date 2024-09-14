#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T> class Array
{
private:
  T *elements;
  unsigned int length;

public:
  // Default constructor
  Array() : elements(NULL), length(0)
  {
  }

  // Constructor with size
  Array(unsigned int n) : elements(new T[n]()), length(n)
  {
  }

  // Copy constructor
  Array(const Array &other)
      : elements(new T[other.length]), length(other.length)
  {
    for(unsigned int i = 0; i < length; ++i)
    {
      elements[i] = other.elements[i];
    }
  }

  // Assignment operator
  Array &operator=(const Array &other)
  {
    if(this != &other)
    {
      delete[] elements;
      length = other.length;
      elements = new T[length];
      for(unsigned int i = 0; i < length; ++i)
      {
        elements[i] = other.elements[i];
      }
    }
    return *this;
  }

  // Destructor
  ~Array()
  {
    delete[] elements;
  }

  // Subscript operator
  T &operator[](unsigned int index)
  {
    if(index >= length)
    {
      throw std::out_of_range("\033[31mIndex out of bounds\033[0m");
    }
    return elements[index];
  }

  const T &operator[](unsigned int index) const
  {
    if(index >= length)
    {
      throw std::out_of_range("\033[31mIndex out of bounds\033[0m");
    }
    return elements[index];
  }

  // Size function
  unsigned int size() const
  {
    return length;
  }
};

#endif