
#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
  if(argc < 2)
  {
    std::cout << "Error: at least one argument is required." << std::endl;
    return 1;
  }
  PmergeMe pmergeMe(argc, argv);

  if(pmergeMe.getVectorSize() == 0)
  {
    std::cout << "\033[1;31mError: Invalid input.\033[0m" << std::endl;
    return 1;
  }
  // Imprimir secuencia antes de ordenar
  std::cout << "\033[36mBefore:\033[0m";
  pmergeMe.printVectorNumbers();
  // Ordenar y medir tiempo con std::vector
  clock_t startVector = clock();
  pmergeMe.mergeInsertSortVector();
  clock_t endVector = clock();
  std::cout << "\033[34m After:\033[0m";
  pmergeMe.printVectorNumbers();

  // Ordenar y medir tiempo con std::deque
  clock_t startDeque = clock();
  pmergeMe.mergeInsertSortDeque();
  clock_t endDeque = clock();

  std::cout << "\033[35mTime to process a range of " << pmergeMe.getVectorSize()
            << " elements with std::vector: "
            << (static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC) *
                   1000000 <<  " µs" << std::endl;
  std::cout << "\033[32mTime to process a range of " << pmergeMe.getDequeSize()
            << " elements with std::deque : "
            << (static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC) *
                   1000000
            << " µs\033[0m" << std::endl;

  return 0;
}