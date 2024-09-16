#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>

class Span {
public:
    Span(unsigned int N);
    
    void addNumber(int number);
    void insertNumbers(const std::vector<int>& moreNumbers);
    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end) {
        if (std::distance(begin, end) + numbers.size() > max_size) {
            throw std::out_of_range("Adding these numbers would exceed the Span's capacity");
        }
        numbers.insert(numbers.end(), begin, end);
    }
    
    int shortestSpan() const;
    int longestSpan() const;

private:
    unsigned int max_size;
    std::vector<int> numbers;
};

#endif // SPAN_HPP
