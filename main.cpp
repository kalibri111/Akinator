#include <cstring>

#include "config.h"
#include "Tree/Tree.h"
#include "Parser/Parser.h"
#include "Lib/filestuff.h"
#include "Callbacks/Callbacks.h"


int main() {
    Tree* tree = newTree();
    Parser parser;

    FILE* tree_container = fopen(tree_container_file, "r");

    size_t file_size = getFileSize(tree_container);
    char* file_data = (char*)calloc(file_size, sizeof(char));

    fread(file_data, sizeof(char), file_size, tree_container);


    parser.parse(file_data, tree);

    fclose(tree_container);

    char user_input[30] = {};
    while (1) {
        printf("What shall we do?\n");
        scanf("%s", user_input);
        if (!strcmp(user_input, "akinator")){

            tree->traversal(node_yes_no_callback, add_node_callback, dump_tree_callback);

        } else if (!strcmp(user_input, "describe")) {

            scanf("%s", user_input);
            tree->find_path(user_input, node_describe_callback);

        }  else if (!strcmp(user_input, "exit")) {

            break;

        }
    }

    destroyTree(tree);
    free(file_data);
}
