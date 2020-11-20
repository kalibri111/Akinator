//
// Created by kalibri on 15.11.2020.
//

#include "Parser.h"

const int MAX_COMMAND_LENGTH = 50;
const int MAX_NODE_LENGTH    = 5000;

strview_t* Parser::behind_scopes(char *text) {
    strview_t* behind_scopes = new_strview();

    behind_scopes->str = text;

    while (*behind_scopes->str) {
        if (*behind_scopes->str == '"') {
            ++(behind_scopes->str);

            while (behind_scopes->str[behind_scopes->strlen] != '"') {
                ++(behind_scopes->strlen);
            }
            break;

        } else {
            ++(behind_scopes->str);
        }
    }
    return behind_scopes;
}

strview_t* Parser::node_name(char *text) {

    strview_t* node_name = new_strview();

    node_name->str = text;
    bool is_scope_ex = false;
    while (*(node_name->str)) {
        if (*(node_name->str) == '[') {
            is_scope_ex = true;
            break;
        }
        ++(node_name->str);
    }
    node_name->str = text;

//    list case
    if (!is_scope_ex) {
        node_name->str    = "";
        node_name->strlen = 0;
        return node_name;
    }

    char* on_scope_pointer = node_name->str;
    destruct_strview(node_name);
    return behind_scopes(on_scope_pointer);
}

strview_t* Parser::node_yes(char *text) {
    strview_t* node_yes = new_strview();

    node_yes->str = text;

    bool is_scope_ex = false;
    while (*node_yes->str) {
        if (*node_yes->str == '[') {
            is_scope_ex = true;
            break;
        }
        ++node_yes->str;
    }
    node_yes->str = text;

//    list case
    if (!is_scope_ex) {
        char* tmp = node_yes->str;
        destruct_strview(node_yes);
        return behind_scopes(tmp);
    }

    node_yes->str = text;

    int scope_balance = 0;

    u_int16_t node_yes_ptr = 0;

    while (*(node_yes->str) != '[' and *(node_yes->str)) {
        ++(node_yes->str);
    }

    char* copy = node_yes->str;
    ++(node_yes->str);

    while (*(copy)) {
        if (scope_balance > 0) {
            ++(node_yes->strlen);
        }

        if (*(copy) == '[') {
            ++scope_balance;
        }

        if (*(copy) == ']') {
            --scope_balance;
        }

        if (!scope_balance) {
            break;
        }
        ++(copy);
    }

    return node_yes;
}

strview_t* Parser::node_no(char *text) {
    strview_t* node_no = new_strview();

    node_no->str = text;

    bool is_scope_ex = false;
    while (*(node_no->str)) {
        if (*(node_no->str) == '[') {
            is_scope_ex = true;
            break;
        }
        ++(node_no->str);
    }

//    list case
    node_no->str = text;
    if (!is_scope_ex) {
        int backticks = 0;
        while (backticks != 2) {
            if (*(node_no->str) == '"') {
                ++backticks;
            }
            ++(node_no->str);
        }
        char* tmp = node_no->str;
        destruct_strview(node_no);
        return behind_scopes(tmp);
    }

    int scope_balance = 0;

    u_int16_t node_no_ptr = 0;

    while (*(node_no->str) != '[' and *(node_no->str)) {
        ++(node_no->str);
    }

    while (*(node_no->str)) {
        if (*(node_no->str) == '[') {
            ++scope_balance;
        }

        if (*(node_no->str) == ']') {
            --scope_balance;
        }

        if (!scope_balance) {

            while (*(node_no->str) != '[' and *(node_no->str)) {
                ++(node_no->str);
            }

            char* copy = node_no->str;



            while (*(copy)) {

                if (scope_balance > 0) {
                    ++(node_no->strlen);
                }

                if (*(copy) == '[') {
                    ++scope_balance;
                }

                if (*(copy) == ']') {
                    --scope_balance;
                }

                if (!scope_balance) {
                    return node_no;
                }
                ++(copy);
            }

        }
        ++(node_no->str);
    }

    return node_no;
}

void Parser::parse_node(char *text, Node *node) {
    if (node) {

        strview_t* name     = node_name(text);
        strview_t* yes_node = node_yes(text);
        strview_t* no_node  = node_no(text);

        node->node_name = name;

        if (*(yes_node->str) != '\0') {
            node->yes         = newNode();
            node->yes->parent = node;
        }

        if (*(no_node->str) != '\0') {
            node->no          = newNode();
            node->no->parent  = node;
        }

        if (*(name->str) == '\0') {
            node->yes->node_name = yes_node;
            node->no->node_name  = no_node;
            return;
        }

        parse_node(yes_node->str, node->yes);
        parse_node(no_node->str , node->no );
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
