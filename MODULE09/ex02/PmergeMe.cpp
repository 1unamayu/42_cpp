#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
  // Parsear argumentos y llenar los contenedores
  for(int i = 1; i < argc; ++i)
  {
    int num = atoi(argv[i]);
    if(num <= 0)
    {
      _vecNumbers.clear();
      _deqNumbers.clear();
      std::cout << "Error" << std::endl;
      return;
    }
    _vecNumbers.push_back(num);
    _deqNumbers.push_back(num);
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
    for (std::deque<int>::size_type i = 0; i < 5; ++i)
    {
      std::cout << " " << _deqNumbers[i];
    }
    std::cout << " [...]";
    for (std::deque<int>::size_type i = _deqNumbers.size() - 5; i < _deqNumbers.size(); ++i)
    {
      std::cout << " " << _deqNumbers[i];
    }
  }
  std::cout << std::endl;
}

void PmergeMe::mergeInsertSortVector()
{
  const int K = 10; // Threshold for switching to insertion sort
  std::vector<int> &arr = _vecNumbers;
  int n = arr.size();

  // Insertion sort for small subarrays
  for(int i = 0; i < n; i += K)
  {
    int right = std::min(i + K - 1, n - 1);
    for(int j = i + 1; j <= right; j++)
    {
      int key = arr[j];
      int k = j - 1;
      while(k >= i && arr[k] > key)
      {
        arr[k + 1] = arr[k];
        k--;
      }
      arr[k + 1] = key;
    }
  }

  // Merge sorted subarrays
  for(int size = K; size < n; size = 2 * size)
  {
    for(int left = 0; left < n; left += 2 * size)
    {
      int mid = std::min(left + size - 1, n - 1);
      int right = std::min(left + 2 * size - 1, n - 1);

      if(mid < n - 1)
      {
        std::vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;

        while(i <= mid && j <= right)
        {
          if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
          else
            temp[k++] = arr[j++];
        }

        while(i <= mid)
          temp[k++] = arr[i++];
        while(j <= right)
          temp[k++] = arr[j++];

        for(int i = 0; i < k; i++)
          arr[left + i] = temp[i];
      }
    }
  }
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
  const int K = 10; // Threshold for switching to insertion sort
  std::deque<int> &arr = _deqNumbers;
  int n = arr.size();

  // Insertion sort for small subarrays
  for(int i = 0; i < n; i += K)
  {
    int right = std::min(i + K - 1, n - 1);
    for(int j = i + 1; j <= right; j++)
    {
      int key = arr[j];
      int k = j - 1;
      while(k >= i && arr[k] > key)
      {
        arr[k + 1] = arr[k];
        k--;
      }
      arr[k + 1] = key;
    }
  }

  // Merge sorted subarrays
  for(int size = K; size < n; size = 2 * size)
  {
    for(int left = 0; left < n; left += 2 * size)
    {
      int mid = std::min(left + size - 1, n - 1);
      int right = std::min(left + 2 * size - 1, n - 1);

      if(mid < n - 1)
      {
        std::deque<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;

        while(i <= mid && j <= right)
        {
          if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
          else
            temp[k++] = arr[j++];
        }

        while(i <= mid)
          temp[k++] = arr[i++];
        while(j <= right)
          temp[k++] = arr[j++];

        for(int i = 0; i < k; i++)
          arr[left + i] = temp[i];
      }
    }
  }
}
