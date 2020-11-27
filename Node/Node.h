//
// Created by kalibri on 15.11.2020.
//

#ifndef AKINATOR_NODE_H
#define AKINATOR_NODE_H
#include <cstdlib>
#include "../Lib/filestuff.h"

/*
 *        node
 *      /       \
 * yes              no
 *
 * */
class Node {
public:
    strview_t* node_name;
    Node* yes;
    Node* no;
    Node* parent;
};

Node* newNode();

void destructNode(Node* node);


class NodeVector {
public:
    void push_back(Node* value);
    Node* pop_back();

    Node** buffer;
    size_t size;
    size_t capacity;
};

NodeVector* newNodeVector();

void destructNodeVector(NodeVector* obj);

#endif //AKINATOR_NODE_H
