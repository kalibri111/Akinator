//
// Created by kalibri on 15.11.2020.
//

#ifndef AKINATOR_TREE_H
#define AKINATOR_TREE_H
#include "../Node/Node.h"
#include "../Lib/StringObserver.h"

#include <cstring>


class Tree {
public:
    void traversal(bool (*visit_callback)(Node*), void (*add_node_callback)(Node*, char**), void(*refresh_buff_callback)(Tree*, char*), char** buffer);

    void dfs(char* node_name, Node* node, NodeVector* stack, void (*visit_callback)(Node*, char*, NodeVector*));

    void dfs(FILE* file, Node* node, void (*visit_callback)(Node*, FILE*));

    void find_path(char* node_name, NodeVector* stack, void (*visit_callback)(Node*, char*, NodeVector*));

    Node* root;
};

Tree* newTree();

void destroyTree(Tree* tree);

#endif //AKINATOR_TREE_H
