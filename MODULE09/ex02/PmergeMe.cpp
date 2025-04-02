#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
  // Parsear argumentos y llenar los contenedores
  for(int i = 1; i < argc; ++i)
  {
    // Verificar si es un número válido
    char *endptr;
    long num = strtol(argv[i], &endptr, 10);
    
    // Verificar si la conversión fue exitosa y si está dentro del rango de int
    if(*endptr != '\0' || num <= 0 || num > INT_MAX)
    {
      _vecNumbers.clear();
      _deqNumbers.clear();
      return;
    }
    
    // Verificar duplicados
    for(size_t j = 0; j < _vecNumbers.size(); ++j)
    {
      if(_vecNumbers[j] == static_cast<int>(num))
      {
        _vecNumbers.clear();
        _deqNumbers.clear();
        return;
      }
    }
    
    _vecNumbers.push_back(static_cast<int>(num));
    _deqNumbers.push_back(static_cast<int>(num));
  }
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
  *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
  if(this != &other)
  {
    _vecNumbers = other._vecNumbers;
    _deqNumbers = other._deqNumbers;
  }
  return *this;
}
void PmergeMe::printVectorNumbers()
{
  if (_vecNumbers.size() <= 10)
  {
    for (std::vector<int>::iterator it = _vecNumbers.begin(); it != _vecNumbers.end(); ++it)
    {
      std::cout << " " << *it;
    }
  }
  else
  {
    for (std::vector<int>::size_type i = 0; i < 5; ++i)
    {
      std::cout << " " << _vecNumbers[i];
    }
    std::cout << " [...]";
    for (std::vector<int>::size_type i = _vecNumbers.size() - 5; i < _vecNumbers.size(); ++i)
    {
      std::cout << " " << _vecNumbers[i];
    }
  }
  std::cout << std::endl;
}

void PmergeMe::printDequeNumbers()
{
  if (_deqNumbers.size() <= 10)
  {
    for (std::deque<int>::iterator it = _deqNumbers.begin(); it != _deqNumbers.end(); ++it)
    {
      std::cout << " " << *it;
    }
  }
  else
  {
    for (int i = 0; i < 5; ++i)
    {
      std::cout << " " << _deqNumbers[i];
    }
    std::cout << " [...]";
    for (size_t i = _deqNumbers.size() - 5; i < _deqNumbers.size(); ++i)
    {
      std::cout << " " << _deqNumbers[i];
    }
  }
  std::cout << std::endl;
}

// Función para generar números de Jacobsthal hasta n
std::vector<int> generateJacobsthalNumbers(int n) {
  std::vector<int> jacobsthal;
  jacobsthal.push_back(0);
  jacobsthal.push_back(1);
  
  for (int i = 2; i <= n; i++) {
    jacobsthal.push_back(jacobsthal[i-1] + 2 * jacobsthal[i-2]);
  }
  
  return jacobsthal;
}

// Función para generar la secuencia de inserción basada en Jacobsthal
std::vector<int> generateInsertionSequence(int n) {
  std::vector<int> result;
  std::vector<int> jacobsthal = generateJacobsthalNumbers(n);
  
  // Encontrar el número de Jacobsthal más grande que no exceda n
  size_t maxJIdx = 0;
  while (maxJIdx < jacobsthal.size() && jacobsthal[maxJIdx] <= n) {
    maxJIdx++;
  }
  maxJIdx--;
  
  // Generar la secuencia de inserción
  for (size_t i = 1; i <= maxJIdx; i++) {
    int start = jacobsthal[i-1];
    int end = std::min(jacobsthal[i], n);
    
    for (int j = end; j > start; j--) {
      result.push_back(j - 1);
    }
  }
  
  // Agregar los elementos restantes
  for (int i = jacobsthal[maxJIdx]; i < n; i++) {
    result.push_back(i);
  }
  
  return result;
}

void PmergeMe::mergeInsertSortVector()
{
  std::vector<int> &vec = _vecNumbers;
  
  // Handle special case if there is an odd number of elements
  int odd = -1;
  if (vec.size() % 2 == 1)
  {
    odd = vec.back();
    vec.pop_back();
  }
  
  // Create pairs and sort them (greater first, smaller second)
  std::vector<std::pair<int, int> > pairs;
  for (size_t i = 0; i < vec.size(); i += 2)
  {
    if (i + 1 < vec.size())
    {
      if (vec[i] > vec[i + 1])
        pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
      else
        pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
    }
  }
  
  // Separate into two containers (greater and smaller)
  std::vector<int> left;  // Greater elements
  std::vector<int> right; // Smaller elements
  
  for (size_t i = 0; i < pairs.size(); i++)
  {
    left.push_back(pairs[i].first);
    right.push_back(pairs[i].second);
  }
  
  // Add the odd element to the end of left if it exists
  if (odd != -1)
    left.push_back(odd);
  
  // Sort left using insertion sort
  for (size_t i = 1; i < left.size(); i++)
  {
    int key = left[i];
    int j = i - 1;
    
    while (j >= 0 && left[j] > key)
    {
      left[j + 1] = left[j];
      j--;
    }
    left[j + 1] = key;
  }
  
  // Generate insertion sequence based on Jacobsthal numbers
  std::vector<int> insertionSequence = generateInsertionSequence(right.size());
  
  // Insert elements of right into left using the Jacobsthal sequence
  for (size_t i = 0; i < insertionSequence.size(); i++)
  {
    int idx = insertionSequence[i];
    if (static_cast<size_t>(idx) < right.size()) {
      std::vector<int>::iterator it = std::lower_bound(left.begin(), left.end(), right[idx]);
      left.insert(it, right[idx]);
    }
  }
  
  // Update the original vector with the sorted result
  _vecNumbers = left;
}

int PmergeMe::getVectorSize()
{
  return _vecNumbers.size();
}

int PmergeMe::getDequeSize()
{
  return _deqNumbers.size();
}

void PmergeMe::mergeInsertSortDeque()
{
  std::deque<int> &deq = _deqNumbers;
  
  // Handle special case if there is an odd number of elements
  int odd = -1;
  if (deq.size() % 2 == 1)
  {
    odd = deq.back();
    deq.pop_back();
  }
  
  // Create pairs and sort them (greater first, smaller second)
  std::deque<std::pair<int, int> > pairs;
  for (size_t i = 0; i < deq.size(); i += 2)
  {
    if (i + 1 < deq.size())
    {
      if (deq[i] > deq[i + 1])
        pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
      else
        pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
    }
  }
  
  // Separate into two containers (greater and smaller)
  std::deque<int> left;  // Greater elements
  std::deque<int> right; // Smaller elements
  
  for (size_t i = 0; i < pairs.size(); i++)
  {
    left.push_back(pairs[i].first);
    right.push_back(pairs[i].second);
  }
  
  // Add the odd element to the end of left if it exists
  if (odd != -1)
    left.push_back(odd);
  
  // Sort left using insertion sort
  for (size_t i = 1; i < left.size(); i++)
  {
    int key = left[i];
    int j = i - 1;
    
    while (j >= 0 && left[j] > key)
    {
      left[j + 1] = left[j];
      j--;
    }
    left[j + 1] = key;
  }
  
  // Generate insertion sequence based on Jacobsthal numbers
  std::vector<int> insertionSequence = generateInsertionSequence(right.size());
  
  // Insert elements of right into left using the Jacobsthal sequence
  for (size_t i = 0; i < insertionSequence.size(); i++)
  {
    int idx = insertionSequence[i];
    if (static_cast<size_t>(idx) < right.size()) {
      std::deque<int>::iterator it = std::lower_bound(left.begin(), left.end(), right[idx]);
      left.insert(it, right[idx]);
    }
  }
  
  // Actualizar el deque original con el resultado ordenado
  _deqNumbers = left;
}
