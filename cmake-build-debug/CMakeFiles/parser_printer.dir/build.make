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
CMAKE_COMMAND = /home/perfest/Clion/clion-2020.2.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/perfest/Clion/clion-2020.2.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/perfest/AL_LABS/lab-01-parser

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/perfest/AL_LABS/lab-01-parser/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/parser_printer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/parser_printer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/parser_printer.dir/flags.make

CMakeFiles/parser_printer.dir/sources/parser_printer.cpp.o: CMakeFiles/parser_printer.dir/flags.make
CMakeFiles/parser_printer.dir/sources/parser_printer.cpp.o: ../sources/parser_printer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/perfest/AL_LABS/lab-01-parser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/parser_printer.dir/sources/parser_printer.cpp.o"
	/usr/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/parser_printer.dir/sources/parser_printer.cpp.o -c /home/perfest/AL_LABS/lab-01-parser/sources/parser_printer.cpp

CMakeFiles/parser_printer.dir/sources/parser_printer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parser_printer.dir/sources/parser_printer.cpp.i"
	/usr/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/perfest/AL_LABS/lab-01-parser/sources/parser_printer.cpp > CMakeFiles/parser_printer.dir/sources/parser_printer.cpp.i

CMakeFiles/parser_printer.dir/sources/parser_printer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parser_printer.dir/sources/parser_printer.cpp.s"
	/usr/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/perfest/AL_LABS/lab-01-parser/sources/parser_printer.cpp -o CMakeFiles/parser_printer.dir/sources/parser_printer.cpp.s

# Object files for target parser_printer
parser_printer_OBJECTS = \
"CMakeFiles/parser_printer.dir/sources/parser_printer.cpp.o"

# External object files for target parser_printer
parser_printer_EXTERNAL_OBJECTS =

libparser_printerd.a: CMakeFiles/parser_printer.dir/sources/parser_printer.cpp.o
libparser_printerd.a: CMakeFiles/parser_printer.dir/build.make
libparser_printerd.a: CMakeFiles/parser_printer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/perfest/AL_LABS/lab-01-parser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libparser_printerd.a"
	$(CMAKE_COMMAND) -P CMakeFiles/parser_printer.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/parser_printer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/parser_printer.dir/build: libparser_printerd.a

.PHONY : CMakeFiles/parser_printer.dir/build

CMakeFiles/parser_printer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/parser_printer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/parser_printer.dir/clean

CMakeFiles/parser_printer.dir/depend:
	cd /home/perfest/AL_LABS/lab-01-parser/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/perfest/AL_LABS/lab-01-parser /home/perfest/AL_LABS/lab-01-parser /home/perfest/AL_LABS/lab-01-parser/cmake-build-debug /home/perfest/AL_LABS/lab-01-parser/cmake-build-debug /home/perfest/AL_LABS/lab-01-parser/cmake-build-debug/CMakeFiles/parser_printer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/parser_printer.dir/depend

