#include <cstring>
#include <algorithm>

#include "config.h"
#include "Tree/Tree.h"
#include "Parser/Parser.h"
#include "Lib/filestuff.h"
#include "Callbacks/Callbacks.h"
#include "Lib/StringObserver.h"


int main() {
    Tree* tree = newTree();
    Parser parser;

    FILE* tree_container = fopen(tree_container_file, "r");

    size_t file_size = getFileSize(tree_container);
    char* file_data = (char*)calloc(file_size, sizeof(char));

    fread(file_data, sizeof(char), file_size, tree_container);


    parser.parse(file_data, file_size, tree);

    fclose(tree_container);

    char user_input[30] = {};
    while (1) {
        printf("What shall we do?\n");
        scanf("%s", user_input);
        if (!strcmp(user_input, "akinator")){

            tree->traversal(node_yes_no_callback, add_node_callback, refresh_buffer_callback, &file_data);

        } else if (!strcmp(user_input, "describe")) {

            scanf("%s", user_input);
            tree->find_path(user_input, nullptr, node_describe_callback);

        }  else if (!strcmp(user_input, "exit")) {

            tree_container = fopen(tree_container_file, "w");

            dump_tree_callback(tree->root);

//            tree->save_to_file(tree_container, save_node_callback);
            fputs(file_data, tree_container);
            fclose(tree_container);

            break;

        } else if (!strcmp(user_input, "difference")) {

            NodeVector* first_path  = newNodeVector();
            NodeVector* second_path = newNodeVector();

            char first_user_input [30] = {};
            char second_user_input[30] = {};

            printf("What is first?\n");
            scanf("%s", first_user_input);
            tree->find_path(first_user_input, first_path, node_describe_callback);

            printf("What is second?\n");
            scanf("%s", second_user_input);
            tree->find_path(second_user_input, second_path, node_describe_callback);

            for (int i = 0; i <= std::max(first_path->size, second_path->size); ++i) {

                StringObserver first_name ( first_path->pop_back()->node_name);
                StringObserver second_name(second_path->pop_back()->node_name);

                if (!strcmp(first_name.string, second_name.string)) {
                    printf(
                            "%s is %s and %s is %s\n",
                            first_user_input,
                            first_name.string,
                            second_user_input,
                            second_name.string
                    );
                } else {
                    printf(
                            "%s is %s while %s is %s\n",
                            first_user_input,
                            first_name.string,
                            second_user_input,
                            second_name.string
                    );
                }

            }

        }
    }

    destroyTree(tree);
    free(file_data);
}
