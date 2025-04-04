#include "Point.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Point::Point() : _x(0), _y(0)
{
}
Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y)
{
}
Point::Point(const Point &src) : _x(src._x), _y(src._y)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Point::~Point()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Point &Point::operator=(Point const &rhs)
{
  if(this != &rhs)
  {
    _x = rhs._x;
    _y = rhs._y;
  }
  return *this;
}

std::ostream &operator<<(std::ostream &o, Point const &i)
{
  o << "Value = " << i.getX() << "," << i.getY() << std::endl;
  return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
Fixed Point::getX() const
{
  return _x;
}

Fixed Point::getY() const
{
  return _y;
}
/* ************************************************************************** */