//
// Created by kalibri on 15.11.2020.
//
#include "Callbacks.h"


void dfs(Node* node, FILE* file) {
    if (node) {

        dfs(node->yes, file);
        dfs(node->no , file);

        if (*(node->node_name)) {
            if (node->no) {
                fprintf(file, "%s->%s\n", node->node_name, node->no->node_name);
            }

            if (node->yes) {
                fprintf(file, "%s->%s\n", node->node_name, node->yes->node_name);
            }
        }

    } else {
        return;
    }

}

void dump_tree_callback(Node* root){
    FILE* gr_file = fopen("../graph.gv", "w");
    fprintf(gr_file, "digraph G{\n");

    dfs(root, gr_file);

    fprintf(gr_file, "\n}");

    system("dot -Tpng -o ../vizfile.png ../graph.gv");
}


bool node_yes_no_callback(Node* node) {
    char user_answer[10] = {};

    printf("is %s\n", node->node_name);
    scanf("%s", user_answer);

    if (!strcmp(user_answer, "yes")) {
        return true;
    } else if (!strcmp(user_answer, "no")) {
        return false;
    }

//    an exception case better to use error
    return false;
}

void node_describe_callback(Node* node) {

    printf("%s\n", node->node_name);

    while (node->parent) {
        if (*(node->parent->node_name)) {
            printf(" is %s\n", node->parent->node_name);
        }
        node = node->parent;
    }

}

void add_node_callback(Node* node) {
    printf("What difference?\n");

    Node* new_node      = newNode();
    Node* new_list_node = newNode();
    Node* new_list_yes  = newNode();


    scanf("%s", new_node->node_name);
    printf("What is it?\n");
    scanf("%s", new_list_yes->node_name);

    new_list_node->node_name = "";

    node->parent->yes = new_node;

    new_node->parent = node->parent;
    new_node->yes    = new_list_node;
    new_node->no     = node;

    new_list_node->parent = new_node;
    new_list_node->yes    = new_list_yes;
}
