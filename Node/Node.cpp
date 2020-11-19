//
// Created by kalibri on 15.11.2020.
//

#include "Node.h"

const size_t INIT_BUF_SIZE = 59;


Node* newNode() {
    Node* new_node = (Node*)calloc(1, sizeof(Node));

    new_node->node_name = (char*)calloc(INIT_BUF_SIZE, sizeof(char));

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
