//
// Created by ksenia on 24.10.17.
//

#include "list_node.h"

list_node::list_node(int data, list_node *next, list_node *prev) :
    data(data),
    next(next),
    prev(prev)
{}

/*
bool operator<(const list_node& node1, const list_node& node2){
    if (node1.data < node2.data)
        return true;
    return false;
}
*/