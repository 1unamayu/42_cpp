#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

// Template para swap
template <typename T> void swap(T &x, T &y)
{
  T temp = x;
  x = y;
  y = temp;
}

// Template para min
template <typename T> T min(const T &x, const T &y)
{
  return (x < y) ? x : y;
}

// Template para max
template <typename T> T max(const T &x, const T &y)
{
  return (x > y) ? x : y;
}
#endif