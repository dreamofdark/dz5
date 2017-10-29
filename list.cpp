//
// Created by ksenia on 24.10.17.
//

#include "list.h"

list::list() :
    size(0),
    max_size(10),
    buf(max_size),
    tail(nullptr),
    head(nullptr)
{ }

list::list(const list &rhs) :
    size(0),
    max_size(rhs.max_size),
    buf(rhs.buf),
    tail(nullptr),
    head(nullptr)
{

    list_node* temp = rhs.head;
    while(temp != 0) {
        add_elem(temp->data);
        temp = temp->next;
    }
}

list& list::operator =(const list& rhs) {
    if (this == &rhs)
        return *this;

    max_size = rhs.max_size;
    size = 0;

    buf = rhs.buf;

    head = tail = nullptr;
    list_node *temp = rhs.head;
    while (temp != 0) {
        add_elem(temp->data);
        temp = temp->next;
    }
    return *this;
}

list::~list(){
}

size_t list::get_size() const{
    return size;
}

int list::get_elem(const size_t number) const{
    if (number < 0 || number > size - 1){
        std::cout << "Incorrect position" << std::endl;
        return 0;
    }

    list_node* temp = head;
    size_t i = 0;

    while(i < number )//&& temp != 0)
    {
      //  printf("%zu %p %p %p %d \t",i, temp->prev, temp, temp->next,temp->data);
        temp = temp->next;
        i++;
    }
        return temp->data;
}

bool list::add_elem(const int elem) {
    list_node* new_node = new(buf.allocate()) list_node(elem);
    if (size == max_size){
        std::cout << "Превышено количество элементов";
        return false;
    }
    if(!head)
        head = tail = new_node;
    else {

        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
    size++;
    return true;
}

const list operator+(const list& list1, const list& list2){
    list result;
    size_t size_temp = list1.size + list2.size;
    if (size_temp > result.max_size)
        return result;

    list_node* temp = list1.head;
    while(temp != 0)
    {
        result.add_elem(temp->data);
        temp = temp->next;
    }

    temp = list2.head;
    while(temp != 0)
    {
        result.add_elem(temp->data);
        temp = temp->next;
    }

    return result;
}

void list::sort(){
    for(list_node* node1 = head; node1; node1 = node1->next)
        for(list_node* node2 = head; node2; node2 = node2->next)
            if(node1->data < node2->data){
                int temp = node1->data;
                node1->data = node2->data;
                node2->data = temp;
            }
}

std::ostream& operator<<(std::ostream& out, list& printed_list){
    if(printed_list.size == 0)
      out << "there are no elements in this list" << std::endl;
   else {
        printed_list.sort();
        out << "[ ";
        for (size_t i = 0; i < printed_list.size; i++) {
            printed_list.get_elem(i);
            out << printed_list.get_elem(i) << ' ';
        }
        out << "]" << std::endl;
    }
    return out;
}


