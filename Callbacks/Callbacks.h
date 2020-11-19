//
// Created by kalibri on 15.11.2020.
//

#ifndef AKINATOR_CALLBACKS_H
#define AKINATOR_CALLBACKS_H

#include "../Node/Node.h"

#include <cstdio>
#include <cstring>

bool node_yes_no_callback(Node* node);

void node_describe_callback(Node* node);

void add_node_callback(Node* node);

void dump_tree_callback(Node* root);

#endif //AKINATOR_CALLBACKS_H
