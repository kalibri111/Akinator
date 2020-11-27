//
// Created by kalibri on 15.11.2020.
//
#include "Callbacks.h"


void define(Node* node, FILE* file) {
    if (node) {

        if (node->node_name->str) {
            StringObserver node_name(node->node_name);
            fprintf(file, "\"%s\"\n", node_name.string);

            if (node->no) {
                StringObserver observer(node->no->node_name);

                fprintf(file, "\"%s\"\n", observer.string);
            }

            if (node->yes) {
                StringObserver observer(node->yes->node_name);

                fprintf(file, "\"%s\"\n", observer.string);
            }
        }

        define(node->yes, file);
        define(node->no , file);

    } else {
        return;
    }
}

void describe(Node* node, FILE* file) {
    if (node) {

        char node_name_str[100] = "";
        if (node->node_name->str) {
            StringObserver node_name(node->node_name);
            sprintf(node_name_str, "%s", node_name.string);
        } else {
            StringObserver node_parent(node->parent->node_name);
            sprintf(node_name_str, "%s", node_parent.string);
        }

        if (node->no) {

            if (node->no->node_name) {
                StringObserver observer(node->no->node_name);
                fprintf(file, "\"%s\"->\"%s\"\n", node_name_str, observer.string);
            }
        }

        if (node->yes) {
            if (node->yes->node_name) {
                StringObserver observer(node->yes->node_name);
                fprintf(file, "\"%s\"->\"%s\"\n", node_name_str, observer.string);
            }
        }

        describe(node->yes, file);
        describe(node->no , file);

    } else {
        return;
    }
}



void dump_tree_callback(Node* root){
    FILE* gr_file = fopen("../graph.gv", "a");
    fprintf(gr_file, "digraph G{\n");

    define(root, gr_file);

    describe(root, gr_file);

    fprintf(gr_file, "\n}");

    system("dot -Tpng -o ../vizfile.png ../graph.gv");
}


bool node_yes_no_callback(Node* node) {
    if (node) {
        char user_answer[10] = {};

        StringObserver node_name(node->node_name);

        printf("is %s\n", node_name.string);
        scanf("%s", user_answer);

        if (!strcmp(user_answer, "yes")) {
            return true;
        } else if (!strcmp(user_answer, "no")) {
            return false;
        }
    }
    return false;
}

void node_describe_callback(Node* node, char* node_name, NodeVector* stack) {
    StringObserver node_name_observer(node->node_name);

    if (!strcmp(node_name, node_name_observer.string)) {

        if (!stack)
            printf("%s\n", node_name_observer.string);

        while (node->parent) {

            StringObserver node_parent_observer(node->parent->node_name);

            if (strcmp(node_parent_observer.string, "")) {

                if (stack) {
                    stack->push_back(node->parent);
                } else {
                    printf(" is %s\n", node_parent_observer.string);
                }

            }
            node = node->parent;
        }
    }
}

void add_node_callback(Node* node, char** buffer) {
    printf("What difference?\n");

    char* new_node_name     = (char*)calloc(50, sizeof(char));
    char* new_list_yes_name = (char*)calloc(50, sizeof(char));

    Node* new_node      = newNode();
    Node* new_list_node = newNode();
    Node* new_list_yes  = newNode();


    scanf("%s", new_node_name);

    new_node->node_name->str = new_node_name;
    new_node->node_name->strlen = strlen(new_node_name);

    printf("What is it?\n");
    scanf("%s", new_list_yes_name);

    new_list_yes->node_name->str = new_list_yes_name;
    new_list_yes->node_name->strlen = strlen(new_list_yes_name);

    new_list_node->node_name->str = nullptr;

    node->parent->yes = new_node;

    size_t to_cut = 0;

    if (node->no) {
        to_cut = node->no->node_name->str + node->no->node_name->strlen - *buffer;
    } else if (node->yes) {
        to_cut = node->yes->node_name->str + node->yes->node_name->strlen - *buffer;
    }



    new_node->parent = node->parent;
    new_node->yes    = new_list_node;
    new_node->no     = node;

    new_list_node->parent = new_node;
    new_list_node->yes    = new_list_yes;

    char* new_node_yes_str = (char*)calloc(node->node_name->strlen + 50, sizeof(char));
    size_t new_node_yes_strlen = 0;

    strcat(new_node_yes_str, new_node_name);
    new_node_yes_strlen += strlen(new_node_name);

    strcat(new_node_yes_str + strlen(new_node_name), R"("[")");
    new_node_yes_strlen += 3;

    strcat(new_node_yes_str + strlen(new_node_name) + 3, new_list_yes_name);
    new_node_yes_strlen += strlen(new_list_yes_name);

    strcat(new_node_yes_str + strlen(new_node_name) + 3 + strlen(new_list_yes_name), R"("][")");
    new_node_yes_strlen += 4;

    size_t node_yes_ptr = 0;
    while (node->yes->node_name->str[node_yes_ptr] != ']') {
        new_node_yes_str[new_node_yes_strlen] = node->yes->node_name->str[node_yes_ptr];
        ++node_yes_ptr;
        ++new_node_yes_strlen;
    }

    strcat(new_node_yes_str + new_node_yes_strlen++, "]");

    size_t offset = node->yes->node_name->str - *buffer;

    size_t node_yes_strlen = strlen(node->yes->node_name->str);

    char* tmp = (char*)realloc(*buffer, sizeof(char) * (strlen(*buffer) + new_node_yes_strlen));

    if (tmp) {
        *buffer = tmp;
    }

    memcpy(*buffer + offset + new_node_yes_strlen, *buffer + to_cut + 1, node_yes_strlen);

    memcpy(*buffer + offset, new_node_yes_str, new_node_yes_strlen);

    node->yes->node_name->str = *buffer + offset;
    node->yes->node_name->strlen = strlen(new_node_yes_str);
}

void refresh_buffer_callback(Tree* tree, char* buffer) {
    Parser parser;
    parser.parse(buffer, strlen(buffer), tree);
}

