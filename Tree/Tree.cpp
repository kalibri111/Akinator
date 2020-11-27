//
// Created by kalibri on 15.11.2020.
//

#include "Tree.h"

Tree* newTree() {
    Tree* new_tree = (Tree*)calloc(1, sizeof(Tree));
    new_tree->root = nullptr;
    return new_tree;
}

void destroyTree(Tree* tree) {
    if (!tree) {
        return;
    }
    if (tree->root) {
        destructNode(tree->root);
    }
    free(tree);
}

void Tree::traversal(bool (*visit_callback)(Node*), void (*add_node_callback)(Node*, char**), void(*refresh_buff_callback)(Tree*, char*), char** buffer) {
    Node* p_node = root;

    while (true) {
        if (!p_node) {
            return;
        }

        StringObserver name_node(p_node->node_name);

        if (*(name_node.string)) {
            if (visit_callback(p_node)) {
                p_node = p_node->yes;
            } else {

                if (!(p_node->no)) {
                    add_node_callback(p_node, buffer);
                    refresh_buff_callback(this, *buffer);

                    return;
                }

                p_node = p_node->no;
            }
        } else {
            if (visit_callback(p_node->yes)) {
                p_node = nullptr;
            } else if (visit_callback(p_node->no)) {
                p_node = nullptr;
            } else {
                add_node_callback(p_node, buffer);
                refresh_buff_callback(this, *buffer);
                return;
            }
        }
    }

}

void Tree::dfs(char *node_name, Node* node, NodeVector* stack, void (*visit_callback)(Node*, char*, NodeVector*)) {

    if (node) {
        visit_callback(node, node_name, stack);
        dfs(node_name, node->yes, stack, visit_callback);
        dfs(node_name, node->no , stack, visit_callback);
    } else {
        return;
    }
}

void Tree::dfs(FILE* file, Node* node, void (*visit_callback)(Node*, FILE*)) {

    if (node) {
        visit_callback(node, file);
        dfs(file, node->yes, visit_callback);
        dfs(file, node->no , visit_callback);
    } else {
        return;
    }
}

void Tree::find_path(char *node_name, NodeVector* stack, void (*visit_callback)(Node*, char*, NodeVector*)) {
    dfs(node_name, root, stack, visit_callback);
}
