//
// Created by kalibri on 15.11.2020.
//
#include "Callbacks.h"


void dfs(Node* node, FILE* file) {
    if (node) {

        dfs(node->yes, file);
        dfs(node->no , file);

        if (*(node->node_name->str)) {
            if (node->no) {
                fprintf(file, "%s->%s\n", node->node_name->str, node->no->node_name->str);
            }

            if (node->yes) {
                fprintf(file, "%s->%s\n", node->node_name->str, node->yes->node_name->str);
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

    StringObserver node_name(node->node_name);

    printf("is %s\n", node_name.string);
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

    printf("%s\n", node->node_name->str);

    while (node->parent) {
        if (*(node->parent->node_name->str)) {
            printf(" is %s\n", node->parent->node_name->str);
        }
        node = node->parent;
    }

}

void add_node_callback(Node* node) {
    printf("What difference?\n");

    char* new_node_name     = (char*)calloc(50, sizeof(char));
    char* new_list_yes_name = (char*)calloc(50, sizeof(char));

    Node* new_node      = newNode();
    Node* new_list_node = newNode();
    Node* new_list_yes  = newNode();


    scanf("%s", new_node_name);
    new_node->node_name->str = new_node_name;
    printf("What is it?\n");
    scanf("%s", new_list_yes_name);

    new_list_yes->node_name->str = new_list_yes_name;

    new_list_node->node_name->str = "";

    node->parent->yes = new_node;

    new_node->parent = node->parent;
    new_node->yes    = new_list_node;
    new_node->no     = node;

    new_list_node->parent = new_node;
    new_list_node->yes    = new_list_yes;

    char* new_node_yes_str = (char*)calloc(strlen(node->node_name->str) + 50, sizeof(char));

    strcat(new_node_yes_str, new_node_name);
    strcat(new_node_yes_str + strlen(new_node_name), R"([")");
    strcat(new_node_yes_str + strlen(new_node_name) + 2, new_list_yes_name);
    strcat(new_node_yes_str + strlen(new_node_name) + strlen(new_list_yes_name) + 2, R"("][)");

    size_t new_node_ptr = strlen(new_node_name) + strlen(new_list_yes_name) + 2 + 2;
    size_t node_yes_ptr = 0;
    while (node->yes->node_name->str[node_yes_ptr] != ']') {
        new_node_yes_str[new_node_ptr] = node->yes->node_name->str[node_yes_ptr];
        ++node_yes_ptr;
        ++new_node_ptr;
    }

    strcat(new_node_yes_str + new_node_ptr, "]");

//    memcpy(node->yes->node_name->str, new_node_yes_str, new_node_ptr);
    strcat(new_node_yes_str, node->yes->node_name->str + (node_yes_ptr + 1));
    memcpy(node->yes->node_name->str, new_node_yes_str, strlen(new_node_yes_str));
}

void refresh_buffer_callback(Tree* tree, char* buffer) {
    Parser parser;
    parser.parse(buffer, tree);
}

