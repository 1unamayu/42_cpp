#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>
#include <string>
class Point
{

public:
  Point();
  Point(const Fixed x, const Fixed y);
  Point(Point const &src);
  ~Point(); // Destructor

  Point &operator=(Point const &rhs);

  Fixed getX() const;
  Fixed getY() const;

private:
  Fixed _x;
  Fixed _y;
};

std::ostream &operator<<(std::ostream &o, Point const &i);
bool bsp(Point const a, Point const b, Point const c, Point const point);
#endif
