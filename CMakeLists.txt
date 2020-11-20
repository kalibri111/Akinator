cmake_minimum_required(VERSION 3.17)
project(Akinator)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        Akinator

        main.cpp

        Node/Node.cpp Node/Node.h
        Tree/Tree.cpp Tree/Tree.h
        Parser/Parser.cpp Parser/Parser.h
        Lib/filestuff.cpp Lib/filestuff.h
        Callbacks/Callbacks.cpp Callbacks/Callbacks.h
        config.h Lib/strview.h Lib/term_type.h Lib/file_str.h Lib/StringObserver.cpp Lib/StringObserver.h)