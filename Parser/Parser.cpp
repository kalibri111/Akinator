//
// Created by kalibri on 15.11.2020.
//

#include "Parser.h"

const int MAX_COMMAND_LENGTH = 50;
const int MAX_NODE_LENGTH    = 5000;

strview_t* Parser::behind_scopes(char *text) {
    strview_t* behind_scopes = new_strview();

    behind_scopes->str = text;
    behind_scopes->strlen = 0;

    while (*behind_scopes->str) {
        if (*behind_scopes->str == '"') {
            ++(behind_scopes->str);

            char* copy = behind_scopes->str;

            while (*copy != '"') {
                ++(behind_scopes->strlen);
                ++copy;
            }
            break;

        } else {
            ++(behind_scopes->str);
        }
    }
    return behind_scopes;
}

strview_t* Parser::node_name(char *text, size_t len) {

    strview_t* node_name = new_strview();

    node_name->str = text;
    bool is_scope_ex = false;
    for (int i = 0; i < len; ++i) {

        if (node_name->str[i] == '[') {
            is_scope_ex = true;
            break;
        }
    }
    node_name->str = text;

//    list case
    if (!is_scope_ex) {
        node_name->str    = nullptr;
        node_name->strlen = 0;
        return node_name;
    }

    char* on_scope_pointer = node_name->str;
    destruct_strview(node_name);
    return behind_scopes(on_scope_pointer);
}

strview_t* Parser::node_yes(char *text, size_t len) {
    strview_t* node_yes = new_strview();

    node_yes->str = text;

    bool is_scope_ex = false;
    for (int i = 0; i < len; ++i) {

        if (node_yes->str[i] == '[') {
            is_scope_ex = true;
            break;
        }
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

strview_t* Parser::node_no(char *text, size_t len) {
    strview_t* node_no = new_strview();

    if (!*text) {
        return node_no;
    }

    node_no->str = text;

    bool is_scope_ex = false;
    for (int i = 0; i < len; ++i) {

        if (node_no->str[i] == '[') {
            is_scope_ex = true;
            break;
        }
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

            while (*(node_no->str) != '\0' and *(node_no->str) != '[') {
                ++(node_no->str);
            }

            char* copy = ++(node_no->str);



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

void Parser::parse_node(char *text, size_t len, Node *node) {
    if (node) {

        strview_t* name     = node_name(text, len);
        strview_t* yes_node = node_yes(text, len);
        strview_t* no_node  = node_no(text, len);

        printf("name: %s\n", StringObserver(name).string);
        printf("yes: %s\n", StringObserver(yes_node).string);
        printf("no: %s\n", StringObserver(no_node).string);
        printf("------------------------------\n");

        node->node_name = name;

        if (yes_node->str and *(yes_node->str) != '\0') {
            node->yes         = newNode();
            node->yes->parent = node;
        }

        if (no_node->str and *(no_node->str) != '\0') {
            node->no          = newNode();
            node->no->parent  = node;
        }

        if (!(name->str)) {
            node->yes->node_name = yes_node;
            node->no->node_name  = no_node;
            return;
        }

        parse_node(yes_node->str, yes_node->strlen, node->yes);
        parse_node(no_node->str , yes_node->strlen, node->no );
    } else {
        return;
    }
}

void Parser::parse(char *text, size_t len, Tree *tree) {
    if (!tree->root) {
        tree->root = (Node*)calloc(1, sizeof(Node));
    }

    parse_node(text, len, tree->root);
}
