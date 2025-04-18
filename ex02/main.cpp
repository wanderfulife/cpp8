#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "MutantStack.hpp"

template <typename TContainer>
void printContainer(TContainer& container, const std::string& name) {
    std::cout << "Contents of " << name << ": [ ";
    typename TContainer::iterator it = container.begin();
    typename TContainer::iterator ite = container.end();
    while (it != ite) {
        std::cout << *it << (it + 1 == ite ? "" : ", ");
        ++it;
    }
    std::cout << " ]" << std::endl;
}

int main()
{
    std::cout << "--- Subject Test with MutantStack<int> ---" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Iterating through MutantStack:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "\nCreating std::stack s(mstack)..." << std::endl;
    std::stack<int> s(mstack);
    std::cout << "std::stack 's' size: " << s.size() << std::endl;
    std::cout << "std::stack 's' top: " << s.top() << std::endl;


    std::cout << "\n--- Comparison Test with std::list<int> ---" << std::endl;
    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << "Back: " << mlist.back() << std::endl;
    mlist.pop_back();
    std::cout << "Size: " << mlist.size() << std::endl;
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);

    std::cout << "Iterating through std::list:" << std::endl;
    std::list<int>::iterator itl = mlist.begin();
    std::list<int>::iterator itle = mlist.end();
    ++itl;
    --itl;
    while (itl != itle)
    {
        std::cout << *itl << std::endl;
        ++itl;
    }

    std::cout << "\n--- Additional Tests ---" << std::endl;
    MutantStack<std::string> str_stack;
    str_stack.push("hello");
    str_stack.push("world");
    str_stack.push("c++");
    printContainer(str_stack, "str_stack");

    std::cout << "Reverse iterating through str_stack: [ ";
    MutantStack<std::string>::reverse_iterator rit = str_stack.rbegin();
    MutantStack<std::string>::reverse_iterator rite = str_stack.rend();
     while (rit != rite) {
        std::cout << *rit << (rit + 1 == rite ? "" : ", ");
        ++rit;
    }
    std::cout << " ]" << std::endl;

    MutantStack<int> mstack_copy = mstack;
    MutantStack<int> mstack_assign;
    mstack_assign = mstack;
    mstack.push(999);
    std::cout << "\nOriginal mstack after push(999):" << std::endl;
    printContainer(mstack, "mstack");
    std::cout << "Copied mstack_copy (should be unchanged):" << std::endl;
    printContainer(mstack_copy, "mstack_copy");
     std::cout << "Assigned mstack_assign (should be unchanged):" << std::endl;
    printContainer(mstack_assign, "mstack_assign");


    return 0;
} 