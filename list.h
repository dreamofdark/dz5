//
// Created by ksenia on 24.10.17.
//

#ifndef HW5_2_LIST_H
#define HW5_2_LIST_H

#include "list_buffer.h"
#include "list_node.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string.h>

class list {
public:
    list();
    list(const list &rhs);
    list& operator =(const list& rhs);
    ~list();

    void sort();

    size_t get_size() const;
    int get_elem(const size_t number) const;
    bool add_elem(const int elem);

    friend const list operator+(const list& list1,const list& list2);
    friend std::ostream& operator<<(std::ostream& out, list& printed_list);
private:
    size_t size;
    size_t max_size;
    list_buffer buf;
    list_node* tail;
    list_node* head;
};


#endif //HW5_2_LIST_H
