//
// Created by kalibri on 15.11.2020.
//

#ifndef AKINATOR_NODE_H
#define AKINATOR_NODE_H
#include <cstdlib>

/*
 *        node
 *      /       \
 * yes              no
 *
 * */
class Node {
public:
    char* node_name;
    Node* yes;
    Node* no;
    Node* parent;
};

Node* newNode();

void destructNode(Node* node);


#endif //AKINATOR_NODE_H
