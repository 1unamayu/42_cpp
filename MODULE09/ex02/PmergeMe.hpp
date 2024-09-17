#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <ctime>
#include <deque>
#include <iostream>
#include <vector>
class PmergeMe
{
public:
  PmergeMe(int argc, char **argv);
  ~PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  void mergeInsertSortVector();
  void mergeInsertSortDeque();
  void printVectorNumbers();
  void printDequeNumbers();
  int getVectorSize();
  int getDequeSize();

private:
  std::vector<int> _vecNumbers;
  std::deque<int> _deqNumbers;
};

#endif
