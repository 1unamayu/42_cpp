#include "Point.hpp"

static Fixed area(const Point p1, const Point p2, const Point p3)
{
  Fixed area;

  area = (p1.getX() * (p2.getY() - p3.getY()) +
          p2.getX() * (p3.getY() - p1.getY()) +
          p3.getX() * (p1.getY() - p2.getY())) /
         2;
  if(area < 0)
    return Fixed(0) - area;
  return area;
}
bool bsp(Point a, Point b, Point c, Point point)
{
  float epsilon = 0.01f;
  Fixed A(area(a, b, c));
  Fixed A1(area(a, b, point));
  Fixed A2(area(a, c, point));
  Fixed A3(area(b, c, point));

  // std::cout << "Area " << A << std::endl;
  // std::cout << "Area1 " << A1 << std::endl;
  // std::cout << "Area2 " << A2 << std::endl;
  // std::cout << "Area3 " << A3 << std::endl;
  // std::cout << "Area4 " << A1 + A2 + A3 << std::endl;

  if(A == 0)
  {
    std::cout << KRED " (A == 0 not a triangle!!) " KNOR;
    return false;
  }

  if(A1 == 0 || A2 == 0 || A3 == 0)
    return false;
  if(A > (A1 + A2 + A3) && A < (A1 + A2 + A3) + Fixed(epsilon))
    return true;
  if(A < (A1 + A2 + A3) && A > (A1 + A2 + A3) + Fixed(epsilon))
    return true;
  return A == A1 + A2 + A3;
}