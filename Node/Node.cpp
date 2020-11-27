//
// Created by kalibri on 15.11.2020.
//

#include "Node.h"

const size_t INIT_BUF_SIZE = 59;


Node* newNode() {
    Node* new_node = (Node*)calloc(1, sizeof(Node));

    new_node->node_name = new_strview();

    new_node->yes     = nullptr;
    new_node->no      = nullptr;
    new_node->parent  = nullptr;


    return new_node;
}

void destructNode(Node* node) {
    if (node) {
        destructNode(node->yes);
        destructNode(node->no);
        free(node);
    }
}

NodeVector* newNodeVector() {
    NodeVector* self = (NodeVector*)calloc(1, sizeof(NodeVector));
    self->buffer = (Node**)calloc(100, sizeof(Node*));
    self->size   = 0;

    self->capacity = 100;

    return self;
}

void destructNodeVector(NodeVector* obj) {
    if (obj) {
        if (obj->buffer) {
            free(obj->buffer);
        }
        free(obj);
    }
}

void NodeVector::push_back(Node *value) {
    if (size == capacity) {
        buffer = (Node**)realloc(buffer, size*2);
        capacity = size*2;
    }
    buffer[size] = value;
    ++size;
}

Node* NodeVector::pop_back() {
    --size;
    return buffer[size];
}
