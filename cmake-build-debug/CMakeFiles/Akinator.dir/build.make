# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/129/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/129/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kalibri/MIPT/1_sem/Dedinsky/Akinator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kalibri/MIPT/1_sem/Dedinsky/Akinator/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Akinator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Akinator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Akinator.dir/flags.make

CMakeFiles/Akinator.dir/main.cpp.o: CMakeFiles/Akinator.dir/flags.make
CMakeFiles/Akinator.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kalibri/MIPT/1_sem/Dedinsky/Akinator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Akinator.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Akinator.dir/main.cpp.o -c /home/kalibri/MIPT/1_sem/Dedinsky/Akinator/main.cpp

CMakeFiles/Akinator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Akinator.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kalibri/MIPT/1_sem/Dedinsky/Akinator/main.cpp > CMakeFiles/Akinator.dir/main.cpp.i

CMakeFiles/Akinator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Akinator.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kalibri/MIPT/1_sem/Dedinsky/Akinator/main.cpp -o CMakeFiles/Akinator.dir/main.cpp.s

CMakeFiles/Akinator.dir/Node/Node.cpp.o: CMakeFiles/Akinator.dir/flags.make
CMakeFiles/Akinator.dir/Node/Node.cpp.o: ../Node/Node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kalibri/MIPT/1_sem/Dedinsky/Akinator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Akinator.dir/Node/Node.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Akinator.dir/Node/Node.cpp.o -c /home/kalibri/MIPT/1_sem/Dedinsky/Akinator/Node/Node.cpp

CMakeFiles/Akinator.dir/Node/Node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Akinator.dir/Node/Node.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kalibri/MIPT/1_sem/Dedinsky/Akinator/Node/Node.cpp > CMakeFiles/Akinator.dir/Node/Node.cpp.i

CMakeFiles/Akinator.dir/Node/Node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Akinator.dir/Node/Node.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kalibri/MIPT/1_sem/Dedinsky/Akinator/Node/Node.cpp -o CMakeFiles/Akinator.dir/Node/Node.cpp.s

CMakeFiles/Akinator.dir/Tree/Tree.cpp.o: CMakeFiles/Akinator.dir/flags.make
CMakeFiles/Akinator.dir/Tree/Tree.cpp.o: ../Tree/Tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kalibri/MIPT/1_sem/Dedinsky/Akinator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Akinator.dir/Tree/Tree.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Akinator.dir/Tree/Tree.cpp.o -c /home/kalibri/MIPT/1_sem/Dedinsky/Akinator/Tree/Tree.cpp

CMakeFiles/Akinator.dir/Tree/Tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Akinator.dir/Tree/Tree.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kalibri/MIPT/1_sem/Dedinsky/Akinator/Tree/Tree.cpp > CMakeFiles/Akinator.dir/Tree/Tree.cpp.i

CMakeFiles/Akinator.dir/Tree/Tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Akinator.dir/Tree/Tree.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kalibri/MIPT/1_sem/Dedinsky/Akinator/Tree/Tree.cpp -o CMakeFiles/Akinator.dir/Tree/Tree.cpp.s

CMakeFiles/Akinator.dir/Parser/Parser.cpp.o: CMakeFiles/Akinator.dir/flags.make
CMakeFiles/Akinator.dir/Parser/Parser.cpp.o: ../Parser/Parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kalibri/MIPT/1_sem/Dedinsky/Akinator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Akinator.dir/Parser/Parser.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Akinator.dir/Parser/Parser.cpp.o -c /home/kalibri/MIPT/1_sem/Dedinsky/Akinator/Parser/Parser.cpp

CMakeFiles/Akinator.dir/Parser/Parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Akinator.dir/Parser/Parser.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kalibri/MIPT/1_sem/Dedinsky/Akinator/Parser/Parser.cpp > CMakeFiles/Akinator.dir/Parser/Parser.cpp.i

CMakeFiles/Akinator.dir/Parser/Parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Akinator.dir/Parser/Parser.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kalibri/MIPT/1_sem/Dedinsky/Akinator/Parser/Parser.cpp -o CMakeFiles/Akinator.dir/Parser/Parser.cpp.s

CMakeFiles/Akinator.dir/Lib/filestuff.cpp.o: CMakeFiles/Akinator.dir/flags.make
CMakeFiles/Akinator.dir/Lib/filestuff.cpp.o: ../Lib/filestuff.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kalibri/MIPT/1_sem/Dedinsky/Akinator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Akinator.dir/Lib/filestuff.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Akinator.dir/Lib/filestuff.cpp.o -c /home/kalibri/MIPT/1_sem/Dedinsky/Akinator/Lib/filestuff.cpp

CMakeFiles/Akinator.dir/Lib/filestuff.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Akinator.dir/Lib/filestuff.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kalibri/MIPT/1_sem/Dedinsky/Akinator/Lib/filestuff.cpp > CMakeFiles/Akinator.dir/Lib/filestuff.cpp.i

CMakeFiles/Akinator.dir/Lib/filestuff.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Akinator.dir/Lib/filestuff.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kalibri/MIPT/1_sem/Dedinsky/Akinator/Lib/filestuff.cpp -o CMakeFiles/Akinator.dir/Lib/filestuff.cpp.s

CMakeFiles/Akinator.dir/Callbacks/Callbacks.cpp.o: CMakeFiles/Akinator.dir/flags.make
CMakeFiles/Akinator.dir/Callbacks/Callbacks.cpp.o: ../Callbacks/Callbacks.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kalibri/MIPT/1_sem/Dedinsky/Akinator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Akinator.dir/Callbacks/Callbacks.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Akinator.dir/Callbacks/Callbacks.cpp.o -c /home/kalibri/MIPT/1_sem/Dedinsky/Akinator/Callbacks/Callbacks.cpp

CMakeFiles/Akinator.dir/Callbacks/Callbacks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Akinator.dir/Callbacks/Callbacks.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kalibri/MIPT/1_sem/Dedinsky/Akinator/Callbacks/Callbacks.cpp > CMakeFiles/Akinator.dir/Callbacks/Callbacks.cpp.i

CMakeFiles/Akinator.dir/Callbacks/Callbacks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Akinator.dir/Callbacks/Callbacks.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kalibri/MIPT/1_sem/Dedinsky/Akinator/Callbacks/Callbacks.cpp -o CMakeFiles/Akinator.dir/Callbacks/Callbacks.cpp.s

# Object files for target Akinator
Akinator_OBJECTS = \
"CMakeFiles/Akinator.dir/main.cpp.o" \
"CMakeFiles/Akinator.dir/Node/Node.cpp.o" \
"CMakeFiles/Akinator.dir/Tree/Tree.cpp.o" \
"CMakeFiles/Akinator.dir/Parser/Parser.cpp.o" \
"CMakeFiles/Akinator.dir/Lib/filestuff.cpp.o" \
"CMakeFiles/Akinator.dir/Callbacks/Callbacks.cpp.o"

# External object files for target Akinator
Akinator_EXTERNAL_OBJECTS =

Akinator: CMakeFiles/Akinator.dir/main.cpp.o
Akinator: CMakeFiles/Akinator.dir/Node/Node.cpp.o
Akinator: CMakeFiles/Akinator.dir/Tree/Tree.cpp.o
Akinator: CMakeFiles/Akinator.dir/Parser/Parser.cpp.o
Akinator: CMakeFiles/Akinator.dir/Lib/filestuff.cpp.o
Akinator: CMakeFiles/Akinator.dir/Callbacks/Callbacks.cpp.o
Akinator: CMakeFiles/Akinator.dir/build.make
Akinator: CMakeFiles/Akinator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kalibri/MIPT/1_sem/Dedinsky/Akinator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable Akinator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Akinator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Akinator.dir/build: Akinator

.PHONY : CMakeFiles/Akinator.dir/build

CMakeFiles/Akinator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Akinator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Akinator.dir/clean

CMakeFiles/Akinator.dir/depend:
	cd /home/kalibri/MIPT/1_sem/Dedinsky/Akinator/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kalibri/MIPT/1_sem/Dedinsky/Akinator /home/kalibri/MIPT/1_sem/Dedinsky/Akinator /home/kalibri/MIPT/1_sem/Dedinsky/Akinator/cmake-build-debug /home/kalibri/MIPT/1_sem/Dedinsky/Akinator/cmake-build-debug /home/kalibri/MIPT/1_sem/Dedinsky/Akinator/cmake-build-debug/CMakeFiles/Akinator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Akinator.dir/depend

