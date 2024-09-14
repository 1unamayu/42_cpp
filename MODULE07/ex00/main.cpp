#include "whatever.hpp"
#include <iostream>

void test_subject_int(void)
{
  int a = 2;
  int b = 3;
  ::swap(a, b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
  
}
void test_subject_string(void)
{
  std::string c = "chaine1";
  std::string d = "chaine2";
  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
  std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
}
void test_float(void)
{
  float a = 2.5f;
  float b = 3.5f;
  ::swap(a, b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
}

void test_char(void)
{
  char a = 'a';
  char b = 'b';
  ::swap(a, b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
}

int main(void)
{
  std::cout << "\033[1;33m---------- Test subject int ----------\033[0m" << std::endl;
  test_subject_int();
  std::cout << "\033[1;33m---------- Test subject string ----------\033[0m" << std::endl;
  test_subject_string();
  std::cout << "\033[1;33m---------- Test float ----------\033[0m" << std::endl;
  test_float();
  std::cout << "\033[1;33m---------- Test char ----------\033[0m" << std::endl;
  test_char();
  return 0;
}
