//
// Created by kalibri on 15.11.2020.
//

#ifndef AKINATOR_PARSER_H
#define AKINATOR_PARSER_H
#include "../Tree/Tree.h"

class Parser {
public:
    void         parse(char* text, Tree* tree);

    void         parse_node(char* text, Node* node);

    char*        node_name(char* text);

    char*        node_yes(char* text);
    char*        node_no(char* text);
    char*        behind_scopes(char* text);

};


#endif //AKINATOR_PARSER_H
