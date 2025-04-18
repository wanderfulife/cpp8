#include "Span.hpp"
#include <algorithm>
#include <limits>
#include <vector>
#include <numeric>
#include <cmath>


Span::Span(unsigned int N) : _maxSize(N) {
    _numbers.reserve(N);
}

Span::Span(const Span &src) : _maxSize(src._maxSize), _numbers(src._numbers) {
    
}

Span& Span::operator=(const Span &rhs) {
    if (this != &rhs) {
        _maxSize = rhs._maxSize;
        _numbers = rhs._numbers;
    }
    return *this;
}

Span::~Span() {
}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw Span::SpanFullException();
    }
    _numbers.push_back(number);
}

long Span::shortestSpan() const {
    if (_numbers.size() <= 1) {
        throw Span::NoSpanException();
    }

    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    long minSpan = std::numeric_limits<long>::max();

    for (std::vector<int>::const_iterator it = sortedNumbers.begin() + 1; it != sortedNumbers.end(); ++it) {
        long diff = static_cast<long>(*it) - static_cast<long>(*(it - 1));
        if (diff < minSpan) {
            minSpan = diff;
        }
    }

    return minSpan;
}

long Span::longestSpan() const {
    if (_numbers.size() <= 1) {
        throw Span::NoSpanException();
    }

    std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());

    return static_cast<long>(*maxIt) - static_cast<long>(*minIt);
}

const char* Span::SpanFullException::what() const throw() {
    return "Span is full, cannot add more numbers.";
}

const char* Span::NoSpanException::what() const throw() {
    return "Not enough numbers stored to find a span (need at least 2).";
}
