# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Documents commun\OneDrive\Documents\VSCode\Test"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Documents commun\OneDrive\Documents\VSCode\Test\build"

# Include any dependencies generated for this target.
include Test/CMakeFiles/CardGamecli.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Test/CMakeFiles/CardGamecli.dir/compiler_depend.make

# Include the progress variables for this target.
include Test/CMakeFiles/CardGamecli.dir/progress.make

# Include the compile flags for this target's objects.
include Test/CMakeFiles/CardGamecli.dir/flags.make

Test/CMakeFiles/CardGamecli.dir/codegen:
.PHONY : Test/CMakeFiles/CardGamecli.dir/codegen

Test/CMakeFiles/CardGamecli.dir/main.cpp.obj: Test/CMakeFiles/CardGamecli.dir/flags.make
Test/CMakeFiles/CardGamecli.dir/main.cpp.obj: Test/CMakeFiles/CardGamecli.dir/includes_CXX.rsp
Test/CMakeFiles/CardGamecli.dir/main.cpp.obj: D:/Documents\ commun/OneDrive/Documents/VSCode/Test/Test/main.cpp
Test/CMakeFiles/CardGamecli.dir/main.cpp.obj: Test/CMakeFiles/CardGamecli.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\Documents commun\OneDrive\Documents\VSCode\Test\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Test/CMakeFiles/CardGamecli.dir/main.cpp.obj"
	cd /d "D:\Documents commun\OneDrive\Documents\VSCode\Test\build\Test" && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Test/CMakeFiles/CardGamecli.dir/main.cpp.obj -MF CMakeFiles\CardGamecli.dir\main.cpp.obj.d -o CMakeFiles\CardGamecli.dir\main.cpp.obj -c "D:\Documents commun\OneDrive\Documents\VSCode\Test\Test\main.cpp"

Test/CMakeFiles/CardGamecli.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CardGamecli.dir/main.cpp.i"
	cd /d "D:\Documents commun\OneDrive\Documents\VSCode\Test\build\Test" && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Documents commun\OneDrive\Documents\VSCode\Test\Test\main.cpp" > CMakeFiles\CardGamecli.dir\main.cpp.i

Test/CMakeFiles/CardGamecli.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CardGamecli.dir/main.cpp.s"
	cd /d "D:\Documents commun\OneDrive\Documents\VSCode\Test\build\Test" && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Documents commun\OneDrive\Documents\VSCode\Test\Test\main.cpp" -o CMakeFiles\CardGamecli.dir\main.cpp.s

Test/CMakeFiles/CardGamecli.dir/src/Carte.cpp.obj: Test/CMakeFiles/CardGamecli.dir/flags.make
Test/CMakeFiles/CardGamecli.dir/src/Carte.cpp.obj: Test/CMakeFiles/CardGamecli.dir/includes_CXX.rsp
Test/CMakeFiles/CardGamecli.dir/src/Carte.cpp.obj: D:/Documents\ commun/OneDrive/Documents/VSCode/Test/Test/src/Carte.cpp
Test/CMakeFiles/CardGamecli.dir/src/Carte.cpp.obj: Test/CMakeFiles/CardGamecli.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\Documents commun\OneDrive\Documents\VSCode\Test\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Test/CMakeFiles/CardGamecli.dir/src/Carte.cpp.obj"
	cd /d "D:\Documents commun\OneDrive\Documents\VSCode\Test\build\Test" && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Test/CMakeFiles/CardGamecli.dir/src/Carte.cpp.obj -MF CMakeFiles\CardGamecli.dir\src\Carte.cpp.obj.d -o CMakeFiles\CardGamecli.dir\src\Carte.cpp.obj -c "D:\Documents commun\OneDrive\Documents\VSCode\Test\Test\src\Carte.cpp"

Test/CMakeFiles/CardGamecli.dir/src/Carte.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CardGamecli.dir/src/Carte.cpp.i"
	cd /d "D:\Documents commun\OneDrive\Documents\VSCode\Test\build\Test" && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Documents commun\OneDrive\Documents\VSCode\Test\Test\src\Carte.cpp" > CMakeFiles\CardGamecli.dir\src\Carte.cpp.i

Test/CMakeFiles/CardGamecli.dir/src/Carte.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CardGamecli.dir/src/Carte.cpp.s"
	cd /d "D:\Documents commun\OneDrive\Documents\VSCode\Test\build\Test" && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Documents commun\OneDrive\Documents\VSCode\Test\Test\src\Carte.cpp" -o CMakeFiles\CardGamecli.dir\src\Carte.cpp.s

Test/CMakeFiles/CardGamecli.dir/src/CreationJoueur.cpp.obj: Test/CMakeFiles/CardGamecli.dir/flags.make
Test/CMakeFiles/CardGamecli.dir/src/CreationJoueur.cpp.obj: Test/CMakeFiles/CardGamecli.dir/includes_CXX.rsp
Test/CMakeFiles/CardGamecli.dir/src/CreationJoueur.cpp.obj: D:/Documents\ commun/OneDrive/Documents/VSCode/Test/Test/src/CreationJoueur.cpp
Test/CMakeFiles/CardGamecli.dir/src/CreationJoueur.cpp.obj: Test/CMakeFiles/CardGamecli.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\Documents commun\OneDrive\Documents\VSCode\Test\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Test/CMakeFiles/CardGamecli.dir/src/CreationJoueur.cpp.obj"
	cd /d "D:\Documents commun\OneDrive\Documents\VSCode\Test\build\Test" && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Test/CMakeFiles/CardGamecli.dir/src/CreationJoueur.cpp.obj -MF CMakeFiles\CardGamecli.dir\src\CreationJoueur.cpp.obj.d -o CMakeFiles\CardGamecli.dir\src\CreationJoueur.cpp.obj -c "D:\Documents commun\OneDrive\Documents\VSCode\Test\Test\src\CreationJoueur.cpp"

Test/CMakeFiles/CardGamecli.dir/src/CreationJoueur.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CardGamecli.dir/src/CreationJoueur.cpp.i"
	cd /d "D:\Documents commun\OneDrive\Documents\VSCode\Test\build\Test" && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Documents commun\OneDrive\Documents\VSCode\Test\Test\src\CreationJoueur.cpp" > CMakeFiles\CardGamecli.dir\src\CreationJoueur.cpp.i

Test/CMakeFiles/CardGamecli.dir/src/CreationJoueur.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CardGamecli.dir/src/CreationJoueur.cpp.s"
	cd /d "D:\Documents commun\OneDrive\Documents\VSCode\Test\build\Test" && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Documents commun\OneDrive\Documents\VSCode\Test\Test\src\CreationJoueur.cpp" -o CMakeFiles\CardGamecli.dir\src\CreationJoueur.cpp.s

Test/CMakeFiles/CardGamecli.dir/src/hello_test.cpp.obj: Test/CMakeFiles/CardGamecli.dir/flags.make
Test/CMakeFiles/CardGamecli.dir/src/hello_test.cpp.obj: Test/CMakeFiles/CardGamecli.dir/includes_CXX.rsp
Test/CMakeFiles/CardGamecli.dir/src/hello_test.cpp.obj: D:/Documents\ commun/OneDrive/Documents/VSCode/Test/Test/src/hello_test.cpp
Test/CMakeFiles/CardGamecli.dir/src/hello_test.cpp.obj: Test/CMakeFiles/CardGamecli.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\Documents commun\OneDrive\Documents\VSCode\Test\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object Test/CMakeFiles/CardGamecli.dir/src/hello_test.cpp.obj"
	cd /d "D:\Documents commun\OneDrive\Documents\VSCode\Test\build\Test" && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Test/CMakeFiles/CardGamecli.dir/src/hello_test.cpp.obj -MF CMakeFiles\CardGamecli.dir\src\hello_test.cpp.obj.d -o CMakeFiles\CardGamecli.dir\src\hello_test.cpp.obj -c "D:\Documents commun\OneDrive\Documents\VSCode\Test\Test\src\hello_test.cpp"

Test/CMakeFiles/CardGamecli.dir/src/hello_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CardGamecli.dir/src/hello_test.cpp.i"
	cd /d "D:\Documents commun\OneDrive\Documents\VSCode\Test\build\Test" && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Documents commun\OneDrive\Documents\VSCode\Test\Test\src\hello_test.cpp" > CMakeFiles\CardGamecli.dir\src\hello_test.cpp.i

Test/CMakeFiles/CardGamecli.dir/src/hello_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CardGamecli.dir/src/hello_test.cpp.s"
	cd /d "D:\Documents commun\OneDrive\Documents\VSCode\Test\build\Test" && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Documents commun\OneDrive\Documents\VSCode\Test\Test\src\hello_test.cpp" -o CMakeFiles\CardGamecli.dir\src\hello_test.cpp.s

# Object files for target CardGamecli
CardGamecli_OBJECTS = \
"CMakeFiles/CardGamecli.dir/main.cpp.obj" \
"CMakeFiles/CardGamecli.dir/src/Carte.cpp.obj" \
"CMakeFiles/CardGamecli.dir/src/CreationJoueur.cpp.obj" \
"CMakeFiles/CardGamecli.dir/src/hello_test.cpp.obj"

# External object files for target CardGamecli
CardGamecli_EXTERNAL_OBJECTS =

Test/bin/Debug/CardGamecli.exe: Test/CMakeFiles/CardGamecli.dir/main.cpp.obj
Test/bin/Debug/CardGamecli.exe: Test/CMakeFiles/CardGamecli.dir/src/Carte.cpp.obj
Test/bin/Debug/CardGamecli.exe: Test/CMakeFiles/CardGamecli.dir/src/CreationJoueur.cpp.obj
Test/bin/Debug/CardGamecli.exe: Test/CMakeFiles/CardGamecli.dir/src/hello_test.cpp.obj
Test/bin/Debug/CardGamecli.exe: Test/CMakeFiles/CardGamecli.dir/build.make
Test/bin/Debug/CardGamecli.exe: CardGame/libCardGame.a
Test/bin/Debug/CardGamecli.exe: Test/CMakeFiles/CardGamecli.dir/linkLibs.rsp
Test/bin/Debug/CardGamecli.exe: Test/CMakeFiles/CardGamecli.dir/objects1.rsp
Test/bin/Debug/CardGamecli.exe: Test/CMakeFiles/CardGamecli.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="D:\Documents commun\OneDrive\Documents\VSCode\Test\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable bin\Debug\CardGamecli.exe"
	cd /d "D:\Documents commun\OneDrive\Documents\VSCode\Test\build\Test" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CardGamecli.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Test/CMakeFiles/CardGamecli.dir/build: Test/bin/Debug/CardGamecli.exe
.PHONY : Test/CMakeFiles/CardGamecli.dir/build

Test/CMakeFiles/CardGamecli.dir/clean:
	cd /d "D:\Documents commun\OneDrive\Documents\VSCode\Test\build\Test" && $(CMAKE_COMMAND) -P CMakeFiles\CardGamecli.dir\cmake_clean.cmake
.PHONY : Test/CMakeFiles/CardGamecli.dir/clean

Test/CMakeFiles/CardGamecli.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Documents commun\OneDrive\Documents\VSCode\Test" "D:\Documents commun\OneDrive\Documents\VSCode\Test\Test" "D:\Documents commun\OneDrive\Documents\VSCode\Test\build" "D:\Documents commun\OneDrive\Documents\VSCode\Test\build\Test" "D:\Documents commun\OneDrive\Documents\VSCode\Test\build\Test\CMakeFiles\CardGamecli.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : Test/CMakeFiles/CardGamecli.dir/depend

