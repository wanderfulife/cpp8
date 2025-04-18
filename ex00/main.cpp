#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <exception>
#include "easyfind.hpp"

int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);

    std::cout << "--- Testing std::vector ---" << std::endl;
    try {
        std::vector<int>::iterator it_vec = easyfind(vec, 30);
        std::cout << "Found value: " << *it_vec << " at index: " << std::distance(vec.begin(), it_vec) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        easyfind(vec, 100);
    } catch (const std::exception& e) {
        std::cerr << "Correctly caught exception for value 100: " << e.what() << std::endl;
    }

    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);

    std::cout << "\n--- Testing std::list ---" << std::endl;
    try {
        std::list<int>::iterator it_lst = easyfind(lst, 4);
        std::cout << "Found value: " << *it_lst << " at index: " << std::distance(lst.begin(), it_lst) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        easyfind(lst, 0);
    } catch (const std::exception& e) {
        std::cerr << "Correctly caught exception for value 0: " << e.what() << std::endl;
    }

    std::deque<int> deq;
    deq.push_back(11);
    deq.push_front(22);
    deq.push_back(33);

    std::cout << "\n--- Testing std::deque ---" << std::endl;
    try {
        std::deque<int>::iterator it_deq = easyfind(deq, 22);
        std::cout << "Found value: " << *it_deq << " at index: " << std::distance(deq.begin(), it_deq) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        easyfind(deq, 99);
    } catch (const std::exception& e) {
        std::cerr << "Correctly caught exception for value 99: " << e.what() << std::endl;
    }
    
    const std::vector<int> const_vec = vec;
    std::cout << "\n--- Testing const std::vector ---" << std::endl;
    try {
        std::vector<int>::const_iterator cit_vec = easyfind(const_vec, 40);
        std::cout << "Found value: " << *cit_vec << " at index: " << std::distance(const_vec.begin(), cit_vec) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        easyfind(const_vec, 100);
    } catch (const std::exception& e) {
        std::cerr << "Correctly caught exception for value 100 in const vector: " << e.what() << std::endl;
    }

    return 0;
} 