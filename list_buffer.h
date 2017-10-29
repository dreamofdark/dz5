//
// Created by ksenia on 24.10.17.
//

#ifndef HW5_2_LIST_BUFFER_H
#define HW5_2_LIST_BUFFER_H

#include <cstddef>
#include <iostream>
#include <fstream>
#include <string.h>
#include "list_node.h"

class list_buffer {
public:
    list_buffer(size_t max_size);
    ~list_buffer();
    list_node* allocate();
    void free(list_node* pos);
    list_buffer& operator =(const list_buffer& rhs);
private:
    list_node* buf;
    size_t first_free;
    size_t max_size;
    size_t size_of_item;
    bool* is_filled_item;
};


#endif //HW5_2_LIST_BUFFER_H
