#include <iostream>
#include "../include/CustomMemoryResource.hpp"
#include "../include/DoublyLinkedList.hpp"
#include <string>

struct ComplexType {
    int a_;
    double b_;
    std::string c_;

    ComplexType(int a, double b, const std::string& c)
        : a_(a), b_(b), c_(c) {}
};

int main() {
    CustomMemoryResource custom_mr;

    DoublyLinkedList<int> int_list(&custom_mr);

    int_list.push_back(10);
    int_list.push_back(20);
    int_list.push_back(30);

    std::cout << "Int list contents:" << std::endl;
    for (auto it = int_list.begin(); it != int_list.end(); ++it) {
        std::cout << *it << std::endl;
    }

    DoublyLinkedList<ComplexType> complex_list(&custom_mr);

    complex_list.push_back(ComplexType(1, 1.1, "one"));
    complex_list.push_back(ComplexType(2, 2.2, "two"));
    complex_list.push_back(ComplexType(3, 3.3, "three"));

    std::cout << "\nComplexType list contents:" << std::endl;
    for (auto it = complex_list.begin(); it != complex_list.end(); ++it) {
        std::cout << "a: " << it->a_ << ", b: " << it->b_ << ", c: " << it->c_ << std::endl;
    }

    return 0;
}
