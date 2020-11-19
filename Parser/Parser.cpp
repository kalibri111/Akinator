//
// Created by kalibri on 15.11.2020.
//

#include "Parser.h"

const int MAX_COMMAND_LENGTH = 50;
const int MAX_NODE_LENGTH    = 5000;

char* Parser::behind_scopes(char *text) {
    char* node_name = (char*)calloc(MAX_COMMAND_LENGTH, sizeof(char));

    u_int16_t node_name_ptr = 0;
    while (*text) {
        if (*text == '"') {
            ++text;

            while (*text != '"') {
                node_name[node_name_ptr++] = *text;
                ++text;
            }
            break;

        } else {
            ++text;
        }
    }
    return node_name;
}

char* Parser::node_name(char *text) {

    char* text_ptr_copy = text;

    int scope_counter = 0;
    while (*text_ptr_copy) {
        if (*text_ptr_copy == '[') {
            ++scope_counter;
        }
        ++text_ptr_copy;
    }

//    list case
    if (!scope_counter) {
        return "";
    }

    return behind_scopes(text);
}

char* Parser::node_yes(char *text) {
    char* node_yes = (char*)calloc(MAX_NODE_LENGTH, sizeof(char));

    char* text_ptr_copy = text;

    int scope_counter = 0;
    while (*text_ptr_copy) {
        if (*text_ptr_copy == '[') {
            ++scope_counter;
        }
        ++text_ptr_copy;
    }

//    list case
    if (!scope_counter) {
        free(node_yes);
        return behind_scopes(text);
    }


    int scope_balance = 0;

    u_int16_t node_yes_ptr = 0;

    while (*text != '[' and *text) {
        ++text;
    }


    while (*text) {
        if (scope_balance > 0) {
            node_yes[node_yes_ptr++] = *text;
        }

        if (*text == '[') {
            ++scope_balance;
        }

        if (*text == ']') {
            --scope_balance;
        }

        if (!scope_balance) {
            break;
        }
        ++text;
    }

    return node_yes;
}

char* Parser::node_no(char *text) {
    char* node_no = (char*)calloc(MAX_NODE_LENGTH, sizeof(char));

    char* text_ptr_copy = text;

    int scope_counter = 0;
    while (*text_ptr_copy) {
        if (*text_ptr_copy == '[') {
            ++scope_counter;
        }
        ++text_ptr_copy;
    }

//    list case
    if (!scope_counter) {
        free(node_no);
        int backticks = 0;
        while (backticks != 2) {
            if (*text == '"') {
                ++backticks;
            }
            ++text;
        }
        return behind_scopes(text);
    }

    int scope_balance = 0;

    u_int16_t node_no_ptr = 0;

    while (*text != '[' and *text) {
        ++text;
    }

    while (*text) {
        if (*text == '[') {
            ++scope_balance;
        }

        if (*text == ']') {
            --scope_balance;
        }

        if (!scope_balance) {
            ++text;

            while (*text != '[' and *text) {
                ++text;
            }

            while (*text) {

                if (scope_balance > 0) {
                    node_no[node_no_ptr++] = *text;
                }

                if (*text == '[') {
                    ++scope_balance;
                }

                if (*text == ']') {
                    --scope_balance;
                }

                if (!scope_balance) {
                    return node_no;
                }
                ++text;
            }

        }
        ++text;
    }

    return node_no;
}

void Parser::parse_node(char *text, Node *node) {
    if (node) {

        char *name     = node_name(text);
        char *yes_node = node_yes(text);
        char *no_node  = node_no(text);

        node->node_name = name;

        if (*yes_node) {
            node->yes = newNode();
            node->yes->parent = node;
        }

        if (*no_node) {
            node->no  = newNode();
            node->no->parent  = node;
        }

        if (*name == '\0') {
            node->yes->node_name = yes_node;
            node->no->node_name  = no_node;
            return;
        }

        parse_node(yes_node, node->yes);
        parse_node(no_node, node->no);
    } else {
        return;
    }
}

void Parser::parse(char *text, Tree *tree) {
    if (!tree->root) {
        tree->root = (Node*)calloc(1, sizeof(Node));
    }

    parse_node(text, tree->root);

}
