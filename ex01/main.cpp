#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "Span.hpp"

int main() {
    std::cout << "--- Subject Test ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test Exceptions ---" << std::endl;
    try {
        Span sp_full = Span(1);
        sp_full.addNumber(1);
        sp_full.addNumber(2);
    } catch (const std::exception& e) {
        std::cerr << "Correctly caught exception (addNumber): " << e.what() << std::endl;
    }

    try {
        Span sp_empty = Span(5);
        sp_empty.shortestSpan();
    } catch (const std::exception& e) {
        std::cerr << "Correctly caught exception (shortestSpan, 0 elements): " << e.what() << std::endl;
    }
    try {
        Span sp_one = Span(5);
        sp_one.addNumber(42);
        sp_one.longestSpan();
    } catch (const std::exception& e) {
        std::cerr << "Correctly caught exception (longestSpan, 1 element): " << e.what() << std::endl;
    }

    std::cout << "\n--- Test Large Span (15000 numbers) ---" << std::endl;
    try {
        Span sp_large(15000);
        std::vector<int> large_vector;
        large_vector.reserve(15000);
        srand(time(0));
        for (int i = 0; i < 15000; ++i) {
            large_vector.push_back(rand());
        }
        sp_large.addRange(large_vector.begin(), large_vector.end());

        std::cout << "Large Shortest Span: " << sp_large.shortestSpan() << std::endl;
        std::cout << "Large Longest Span: " << sp_large.longestSpan() << std::endl;

         try {
             std::vector<int> extra_nums; extra_nums.push_back(1);
             sp_large.addRange(extra_nums.begin(), extra_nums.end());
         } catch (const std::exception& e) {
             std::cerr << "Correctly caught exception (addRange overflow): " << e.what() << std::endl;
         }

    } catch (const std::exception& e) {
        std::cerr << "Error during large span test: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test addRange with different container (list) ---" << std::endl;
    try {
        Span sp_list(10);
        std::list<int> data_list;
        data_list.push_back(100);
        data_list.push_back(200);
        data_list.push_back(50);
        data_list.push_back(150);

        sp_list.addRange(data_list.begin(), data_list.end());
        sp_list.addNumber(25);
        sp_list.addNumber(175);

        std::cout << "List addRange Shortest Span: " << sp_list.shortestSpan() << std::endl;
        std::cout << "List addRange Longest Span: " << sp_list.longestSpan() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error during list addRange test: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test Copy Constructor and Assignment Operator ---" << std::endl;
    try {
        Span sp1(3);
        sp1.addNumber(1);
        sp1.addNumber(10);
        sp1.addNumber(100);

        Span sp2 = sp1;
        Span sp3(1);
        sp3 = sp1;

        std::cout << "sp1 shortest: " << sp1.shortestSpan() << ", longest: " << sp1.longestSpan() << std::endl;
        std::cout << "sp2 shortest: " << sp2.shortestSpan() << ", longest: " << sp2.longestSpan() << std::endl;
        std::cout << "sp3 shortest: " << sp3.shortestSpan() << ", longest: " << sp3.longestSpan() << std::endl;

        sp1.addNumber(5);
    } catch (const std::exception& e) {
         std::cerr << "Error during copy/assignment test: " << e.what() << std::endl;
    }
     try {
         Span sp1(4);
         sp1.addNumber(1);
         sp1.addNumber(10);
         sp1.addNumber(100);
         Span sp2 = sp1;
         sp1.addNumber(5);
         std::cout << "Original sp1 after add (size 4): shortest=" << sp1.shortestSpan() << ", longest=" << sp1.longestSpan() << std::endl;
         std::cout << "Copied sp2 (size 3): shortest=" << sp2.shortestSpan() << ", longest=" << sp2.longestSpan() << std::endl;
     } catch (const std::exception& e) {
         std::cerr << "Error during copy/assignment modification test: " << e.what() << std::endl;
     }


    return 0;
} 