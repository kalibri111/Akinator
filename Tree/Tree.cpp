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

void Tree::traversal(bool (*visit_callback)(Node*), void (*add_node_callback)(Node*), void(*refresh_buff_callback)(Tree*, char*), char* buffer) {
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
                p_node = p_node->no;
            }
        } else {
            if (visit_callback(p_node->yes)) {
                p_node = nullptr;
            } else if (visit_callback(p_node->no)) {
                p_node = nullptr;
            } else {
                add_node_callback(p_node);
                refresh_buff_callback(this, buffer);
                return;
            }
        }
    }

}

void Tree::dfs(char *node_name, Node* node, void (*describe_callback)(Node*)) {

    StringObserver node_name_observer(node->node_name);

    if (node) {
        if (!strcmp(node_name, node_name_observer.string)) {
            describe_callback(node);
        }
        dfs(node_name, node->yes, describe_callback);
        dfs(node_name, node->no, describe_callback);
    } else {
        return;
    }
}

void Tree::find_path(char *node_name, void (*describe_callback)(Node*)) {
    dfs(node_name, root, describe_callback);
}
