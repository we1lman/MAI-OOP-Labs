# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/cmake/bin/cmake

# The command to remove a file.
RM = /opt/cmake/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspaces/MAI-OOP-Labs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/MAI-OOP-Labs/build

# Include any dependencies generated for this target.
include CMakeFiles/test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.dir/flags.make

CMakeFiles/test.dir/tests/function_test.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/tests/function_test.cpp.o: ../tests/function_test.cpp
CMakeFiles/test.dir/tests/function_test.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/MAI-OOP-Labs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test.dir/tests/function_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/tests/function_test.cpp.o -MF CMakeFiles/test.dir/tests/function_test.cpp.o.d -o CMakeFiles/test.dir/tests/function_test.cpp.o -c /workspaces/MAI-OOP-Labs/tests/function_test.cpp

CMakeFiles/test.dir/tests/function_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/tests/function_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/MAI-OOP-Labs/tests/function_test.cpp > CMakeFiles/test.dir/tests/function_test.cpp.i

CMakeFiles/test.dir/tests/function_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/tests/function_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/MAI-OOP-Labs/tests/function_test.cpp -o CMakeFiles/test.dir/tests/function_test.cpp.s

CMakeFiles/test.dir/src/function.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/function.cpp.o: ../src/function.cpp
CMakeFiles/test.dir/src/function.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/MAI-OOP-Labs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test.dir/src/function.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/src/function.cpp.o -MF CMakeFiles/test.dir/src/function.cpp.o.d -o CMakeFiles/test.dir/src/function.cpp.o -c /workspaces/MAI-OOP-Labs/src/function.cpp

CMakeFiles/test.dir/src/function.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/function.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/MAI-OOP-Labs/src/function.cpp > CMakeFiles/test.dir/src/function.cpp.i

CMakeFiles/test.dir/src/function.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/function.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/MAI-OOP-Labs/src/function.cpp -o CMakeFiles/test.dir/src/function.cpp.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/tests/function_test.cpp.o" \
"CMakeFiles/test.dir/src/function.cpp.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

test: CMakeFiles/test.dir/tests/function_test.cpp.o
test: CMakeFiles/test.dir/src/function.cpp.o
test: CMakeFiles/test.dir/build.make
test: lib/libgtest.a
test: lib/libgtest_main.a
test: lib/libgtest.a
test: CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/MAI-OOP-Labs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test.dir/build: test
.PHONY : CMakeFiles/test.dir/build

CMakeFiles/test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test.dir/clean

CMakeFiles/test.dir/depend:
	cd /workspaces/MAI-OOP-Labs/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/MAI-OOP-Labs /workspaces/MAI-OOP-Labs /workspaces/MAI-OOP-Labs/build /workspaces/MAI-OOP-Labs/build /workspaces/MAI-OOP-Labs/build/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test.dir/depend

