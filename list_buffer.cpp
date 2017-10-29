//
// Created by ksenia on 24.10.17.
//

#include "list_buffer.h"
#include <algorithm>

list_buffer::list_buffer(size_t max_size = 10) :
    first_free(0),
    max_size(max_size),
    size_of_item(sizeof(list_node))
{
    buf = (list_node*)malloc(size_of_item * max_size);
    is_filled_item = new bool[max_size];
    for(size_t i = 0; i < max_size; i++)
        is_filled_item[i] = false;
}

list_buffer::~list_buffer() {
    delete[] is_filled_item;
    free(buf);
}

list_node* list_buffer::allocate() {
    if (first_free == max_size)
        return nullptr;

    size_t cur_first_free = first_free;
    is_filled_item[cur_first_free] = true;
    for (first_free = cur_first_free + 1; first_free < max_size; first_free++){
        if (is_filled_item[first_free] == false) {
            break;
        }
    }

    return (buf + cur_first_free * size_of_item);
}

void list_buffer::free(list_node* pos) {
    if(pos >= buf){
        size_t position = (pos - buf) / size_of_item;
        if(buf + size_of_item == pos && position < max_size){
            is_filled_item[position] = false;
            first_free = first_free  > position ? position : first_free;
        }
    }
}

list_buffer& list_buffer::operator =(const list_buffer& rhs){
    if (this == &rhs)
        return *this;

    first_free = rhs.first_free;
    max_size = rhs.max_size;
    size_of_item = rhs.size_of_item;

    memcpy(is_filled_item, rhs.is_filled_item, max_size);
    memcpy(buf, rhs.buf, size_of_item*max_size);
    return *this;
}
