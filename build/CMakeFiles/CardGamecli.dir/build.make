# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspaces/Test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/Test/build

# Include any dependencies generated for this target.
include CMakeFiles/CardGamecli.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CardGamecli.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CardGamecli.dir/flags.make

CMakeFiles/CardGamecli.dir/main.cpp.o: CMakeFiles/CardGamecli.dir/flags.make
CMakeFiles/CardGamecli.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/Test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CardGamecli.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CardGamecli.dir/main.cpp.o -c /workspaces/Test/main.cpp

CMakeFiles/CardGamecli.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CardGamecli.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/Test/main.cpp > CMakeFiles/CardGamecli.dir/main.cpp.i

CMakeFiles/CardGamecli.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CardGamecli.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/Test/main.cpp -o CMakeFiles/CardGamecli.dir/main.cpp.s

# Object files for target CardGamecli
CardGamecli_OBJECTS = \
"CMakeFiles/CardGamecli.dir/main.cpp.o"

# External object files for target CardGamecli
CardGamecli_EXTERNAL_OBJECTS =

CardGamecli: CMakeFiles/CardGamecli.dir/main.cpp.o
CardGamecli: CMakeFiles/CardGamecli.dir/build.make
CardGamecli: libCardGamelib.a
CardGamecli: CMakeFiles/CardGamecli.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/Test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CardGamecli"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CardGamecli.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CardGamecli.dir/build: CardGamecli

.PHONY : CMakeFiles/CardGamecli.dir/build

CMakeFiles/CardGamecli.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CardGamecli.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CardGamecli.dir/clean

CMakeFiles/CardGamecli.dir/depend:
	cd /workspaces/Test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/Test /workspaces/Test /workspaces/Test/build /workspaces/Test/build /workspaces/Test/build/CMakeFiles/CardGamecli.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CardGamecli.dir/depend

