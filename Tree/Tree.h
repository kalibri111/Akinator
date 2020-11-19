//
// Created by kalibri on 15.11.2020.
//

#ifndef AKINATOR_TREE_H
#define AKINATOR_TREE_H
#include "../Node/Node.h"
#include <cstring>

class Tree {
public:
    void traversal(bool (*visit_callback)(Node*), void (*add_node_callback)(Node*), void(*dump_callback)(Node*));

    void dfs(char* node_name, Node* node, void (*describe_callback)(Node*));

    void find_path(char* node_name, void (*describe_callback)(Node*));

    Node* root;
};

Tree* newTree();

void destroyTree(Tree* tree);



#endif //AKINATOR_TREE_H