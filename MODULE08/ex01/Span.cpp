#include "Span.hpp"

Span::Span(unsigned int N) : max_size(N) {}

void Span::addNumber(int number) {
    if (numbers.size() >= max_size) {
        throw std::out_of_range("\033[31mSpan is already full\033[0m");
    }
    numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span");
    }
    std::vector<int> sorted_numbers(numbers);
    std::sort(sorted_numbers.begin(), sorted_numbers.end());
    int min_span = sorted_numbers[1] - sorted_numbers[0];
    for (size_t i = 1; i < sorted_numbers.size() - 1; ++i) {
        int span = sorted_numbers[i + 1] - sorted_numbers[i];
        if (span < min_span) {
            min_span = span;
        }
    }
    return min_span;
}

int Span::longestSpan() const {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span");
    }
    int min_number = *std::min_element(numbers.begin(), numbers.end());
    int max_number = *std::max_element(numbers.begin(), numbers.end());
    return max_number - min_number;
}

void Span::insertNumbers(const std::vector<int>& moreNumbers) {
    if (numbers.size() + moreNumbers.size() > max_size) {
        throw std::out_of_range("\033[31mNo se puede agregar estos números, el span excedería el tamaño máximo\033[0m");
    }
    numbers.insert(numbers.end(), moreNumbers.begin(), moreNumbers.end());
}
