# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\voch1\CLionProjects\Program Assignment 1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\voch1\CLionProjects\Program Assignment 1\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Program_Assignment_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Program_Assignment_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Program_Assignment_1.dir/flags.make

CMakeFiles/Program_Assignment_1.dir/CodeCamp.c.obj: CMakeFiles/Program_Assignment_1.dir/flags.make
CMakeFiles/Program_Assignment_1.dir/CodeCamp.c.obj: ../CodeCamp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\voch1\CLionProjects\Program Assignment 1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Program_Assignment_1.dir/CodeCamp.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Program_Assignment_1.dir\CodeCamp.c.obj   -c "C:\Users\voch1\CLionProjects\Program Assignment 1\CodeCamp.c"

CMakeFiles/Program_Assignment_1.dir/CodeCamp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Program_Assignment_1.dir/CodeCamp.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\voch1\CLionProjects\Program Assignment 1\CodeCamp.c" > CMakeFiles\Program_Assignment_1.dir\CodeCamp.c.i

CMakeFiles/Program_Assignment_1.dir/CodeCamp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Program_Assignment_1.dir/CodeCamp.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\voch1\CLionProjects\Program Assignment 1\CodeCamp.c" -o CMakeFiles\Program_Assignment_1.dir\CodeCamp.c.s

CMakeFiles/Program_Assignment_1.dir/CodeCampTester.c.obj: CMakeFiles/Program_Assignment_1.dir/flags.make
CMakeFiles/Program_Assignment_1.dir/CodeCampTester.c.obj: CodeCampTester.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\voch1\CLionProjects\Program Assignment 1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Program_Assignment_1.dir/CodeCampTester.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Program_Assignment_1.dir\CodeCampTester.c.obj   -c "C:\Users\voch1\CLionProjects\Program Assignment 1\cmake-build-debug\CodeCampTester.c"

CMakeFiles/Program_Assignment_1.dir/CodeCampTester.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Program_Assignment_1.dir/CodeCampTester.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\voch1\CLionProjects\Program Assignment 1\cmake-build-debug\CodeCampTester.c" > CMakeFiles\Program_Assignment_1.dir\CodeCampTester.c.i

CMakeFiles/Program_Assignment_1.dir/CodeCampTester.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Program_Assignment_1.dir/CodeCampTester.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\voch1\CLionProjects\Program Assignment 1\cmake-build-debug\CodeCampTester.c" -o CMakeFiles\Program_Assignment_1.dir\CodeCampTester.c.s

# Object files for target Program_Assignment_1
Program_Assignment_1_OBJECTS = \
"CMakeFiles/Program_Assignment_1.dir/CodeCamp.c.obj" \
"CMakeFiles/Program_Assignment_1.dir/CodeCampTester.c.obj"

# External object files for target Program_Assignment_1
Program_Assignment_1_EXTERNAL_OBJECTS =

Program_Assignment_1.exe: CMakeFiles/Program_Assignment_1.dir/CodeCamp.c.obj
Program_Assignment_1.exe: CMakeFiles/Program_Assignment_1.dir/CodeCampTester.c.obj
Program_Assignment_1.exe: CMakeFiles/Program_Assignment_1.dir/build.make
Program_Assignment_1.exe: CMakeFiles/Program_Assignment_1.dir/linklibs.rsp
Program_Assignment_1.exe: CMakeFiles/Program_Assignment_1.dir/objects1.rsp
Program_Assignment_1.exe: CMakeFiles/Program_Assignment_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\voch1\CLionProjects\Program Assignment 1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Program_Assignment_1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Program_Assignment_1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Program_Assignment_1.dir/build: Program_Assignment_1.exe

.PHONY : CMakeFiles/Program_Assignment_1.dir/build

CMakeFiles/Program_Assignment_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Program_Assignment_1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Program_Assignment_1.dir/clean

CMakeFiles/Program_Assignment_1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\voch1\CLionProjects\Program Assignment 1" "C:\Users\voch1\CLionProjects\Program Assignment 1" "C:\Users\voch1\CLionProjects\Program Assignment 1\cmake-build-debug" "C:\Users\voch1\CLionProjects\Program Assignment 1\cmake-build-debug" "C:\Users\voch1\CLionProjects\Program Assignment 1\cmake-build-debug\CMakeFiles\Program_Assignment_1.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Program_Assignment_1.dir/depend

