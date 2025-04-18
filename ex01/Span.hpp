#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>
#include <iterator

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

    Span();

public:
    explicit Span(unsigned int N);
    Span(const Span &src);
    Span &operator=(const Span &rhs);
    ~Span();

    void addNumber(int number);
    long shortestSpan() const;
    long longestSpan() const;

    template <typename InputIterator>
    void addRange(InputIterator first, InputIterator last);

    class SpanFullException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class NoSpanException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

template <typename InputIterator>
void Span::addRange(InputIterator first, InputIterator last) {
    std::ptrdiff_t rangeSize = std::distance(first, last);
    if (rangeSize < 0) {
        throw std::invalid_argument("Invalid iterator range");
    }

    if (_numbers.size() + static_cast<unsigned int>(rangeSize) > _maxSize) {
        throw SpanFullException();
    }

    _numbers.reserve(_numbers.size() + rangeSize);
    
    _numbers.insert(_numbers.end(), first, last);
}


#endif