#include <iostream>
#include "list.h"

int main() {
    list ex;
    ex.add_elem(3);
    ex.add_elem(0);
    ex.add_elem(7);
    ex.add_elem(2);
    std::cout << "list 1 " << ex;
    list ex2;
    ex2.add_elem(1);
    ex2.add_elem(9);
    ex2.add_elem(5);
    std::cout << "list 2 " << ex2;
    list ex3 = ex + ex2;
    std::cout << "list 3 " << ex3;

    return 0;
}