//
// Created by kalibri on 15.11.2020.
//

#ifndef AKINATOR_CALLBACKS_H
#define AKINATOR_CALLBACKS_H

#include "../Node/Node.h"
#include "../Lib/StringObserver.h"
#include "../Parser/Parser.h"

#include <cstdio>
#include <cstring>

bool node_yes_no_callback(Node* node);

void node_describe_callback(Node* node, char* node_name, NodeVector* stack);

void add_node_callback(Node* node, char** buffer);

void dump_tree_callback(Node* root);

void refresh_buffer_callback(Tree* tree, char* buffer);

void save_node_callback(Node* node, FILE* file);

#endif //AKINATOR_CALLBACKS_H
