#include "MutantStack.hpp"
#include <iostream>
#include <list>

void test_separator(const std::string &separator);
void testPushAndTop(MutantStack<int> &mstack);
void testPopAndSize(MutantStack<int> &mstack);
void testMultiplePushes(MutantStack<int> &mstack);
void testIteration(MutantStack<int> &mstack);
void testConstIteration(const MutantStack<int> &mstack);
void testReverseIteration(MutantStack<int> &mstack);
void testConstReverseIteration(const MutantStack<int> &mstack);
void testEmptyStack(MutantStack<int> &mstack);
void testClearStack(MutantStack<int> &mstack);
void test_subject(void);
void test_subject_list(void);

int main()
{
  MutantStack<int> mstack;
  test_separator("Push and Top");
  testPushAndTop(mstack);
  test_separator("Pop and Size");
  testPopAndSize(mstack);
  test_separator("Multiple Pushes");
  testMultiplePushes(mstack);
  test_separator("Iteration");
  testIteration(mstack);
  test_separator("Reverse Iteration");
  testReverseIteration(mstack);
  test_separator("Empty Stack");
  testEmptyStack(mstack);
  test_separator("Clear Stack");
  testClearStack(mstack);
  test_separator("Empty Stack");
  testEmptyStack(mstack);

  // Pruebas con una pila constante
  mstack.push(42);
  mstack.push(41);
  mstack.push(54);
  mstack.push(44);
  mstack.push(55);
  const MutantStack<int> const_mstack = mstack;

  test_separator("Const Iteration");
  testConstIteration(const_mstack);
  test_separator("Const Reverse Iteration");
  testConstReverseIteration(const_mstack);

  test_separator("Subject");
  test_subject();
  test_separator("Subject with list");
  test_subject_list();

  return 0;
}
void testPushAndTop(MutantStack<int> &mstack)
{
  std::cout << "\033[33m"; // Cambiar color a amarillo
  std::cout << "Pushing 5 and 17 into the stack." << std::endl;
  std::cout << "\033[0m"; // Restablecer color
  mstack.push(5);
  mstack.push(17);
  std::cout << "\033[32m"; // Cambiar color a verde
  std::cout << "Top element after pushes: " << mstack.top() << std::endl;
  std::cout << "\033[0m";  // Restablecer color
  std::cout << "\033[34m"; // Cambiar color a azul
}

void testPopAndSize(MutantStack<int> &mstack)
{
  std::cout << "\033[33m"; // Cambiar color a amarillo
  std::cout << "Popping one element from the stack." << std::endl;
  std::cout << "\033[0m"; // Restablecer color
  mstack.pop();
  std::cout << "\033[32m"; // Cambiar color a verde
  std::cout << "Size after pop: " << mstack.size() << std::endl;
  std::cout << "\033[0m"; // Restablecer color
}

void testMultiplePushes(MutantStack<int> &mstack)
{
  std::cout << "\033[33m"; // Cambiar color a amarillo
  std::cout << "Pushing 3, 5, 737, and 0 into the stack." << std::endl;
  std::cout << "\033[0m"; // Restablecer color
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);
}

void testIteration(MutantStack<int> &mstack)
{
  std::cout << "\033[33m"; // Cambiar color a amarillo
  std::cout << "Elements in stack: ";
  std::cout << "\033[0m"; // Restablecer color
  for(MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}
void testConstIteration(const MutantStack<int> &mstack)
{
  std::cout << "\033[33m"; // Cambiar color a amarillo
  std::cout << "Elements in const stack: ";
  std::cout << "\033[0m"; // Restablecer color
  for(MutantStack<int>::const_iterator it = mstack.begin(); it != mstack.end();
      ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

void testReverseIteration(MutantStack<int> &mstack)
{
  std::cout << "\033[33m"; // Cambiar color a amarillo
  std::cout << "Elements in reverse: ";
  std::cout << "\033[0m"; // Restablecer color
  for(MutantStack<int>::reverse_iterator rit = mstack.rbegin();
      rit != mstack.rend(); ++rit)
  {
    std::cout << *rit << " ";
  }
  std::cout << std::endl;
}
void testConstReverseIteration(const MutantStack<int> &mstack)
{
  std::cout << "\033[33m"; // Cambiar color a amarillo
  std::cout << "Elements in const reverse: ";
  std::cout << "\033[0m"; // Restablecer color
  for(MutantStack<int>::const_reverse_iterator rit = mstack.rbegin();
      rit != mstack.rend(); ++rit)
  {
    std::cout << *rit << " ";
  }
  std::cout << std::endl;
}

void testEmptyStack(MutantStack<int> &mstack)
{
  std::cout << "\033[33m"; // Cambiar color a amarillo
  std::cout << "Is stack empty? \033[0m" << (mstack.empty() ? "Yes" : "No")
            << std::endl;
  std::cout << "\033[0m"; // Restablecer color
}

void testClearStack(MutantStack<int> &mstack)
{
  std::cout << "\033[33m"; // Cambiar color a amarillo
  std::cout << "Clearing the stack." << std::endl;
  std::cout << "\033[0m"; // Restablecer color
  while(!mstack.empty())
  {
    mstack.pop();
  }
  std::cout << "Stack cleared. Size: " << mstack.size() << std::endl;
}
void test_separator(const std::string &separator)
{
  std::cout << "\033[34m";
  std::string linea(120, '-');
  size_t inicio = (120 - separator.length()) / 2;
  linea.replace(inicio, separator.length(), separator);
  std::cout << linea << std::endl;
  std::cout << "\033[0m";
}

void test_subject()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while(it != ite)
    {
      std::cout << *it << std::endl;
      ++it;
    }
    std::stack<int> s(mstack);
    
  
}
void test_subject_list()
{
    std::list<int> mstack;
    mstack.push_back(5);
    mstack.push_back(17);
    std::cout << mstack.back() << std::endl;
    mstack.pop_back();
    std::cout << mstack.size() << std::endl;
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    
    mstack.push_back(0);
    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while(it != ite)
    {
      std::cout << *it << std::endl;
      ++it;
    }
   
    
  
}
