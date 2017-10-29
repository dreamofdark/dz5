//
// Created by ksenia on 24.10.17.
//

#ifndef HW5_2_LIST_NODE_H
#define HW5_2_LIST_NODE_H


struct list_node {
    int data;
    list_node* next;
    list_node* prev;

    list_node(int data, list_node* next = nullptr, list_node* prev = nullptr);
    //bool operator<(const list_node& node2);
   // friend bool operator<(const list_node& node1, const list_node& node2);
};


#endif //HW5_2_LIST_NODE_H
