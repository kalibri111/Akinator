//
// Created by kalibri on 15.11.2020.
//

#ifndef AKINATOR_PARSER_H
#define AKINATOR_PARSER_H
#include "../Tree/Tree.h"

class Parser {
public:
    void              parse(char* text, Tree* tree);

    void              parse_node(char* text, Node* node);

    strview_t*        node_name(char* text);

    strview_t*        node_yes(char* text);
    strview_t*        node_no(char* text);
    strview_t*        behind_scopes(char* text);

};


#endif //AKINATOR_PARSER_H
