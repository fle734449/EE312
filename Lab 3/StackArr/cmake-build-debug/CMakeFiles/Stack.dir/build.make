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
CMAKE_SOURCE_DIR = C:\Users\voch1\CLionProjects\Stack

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\voch1\CLionProjects\Stack\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Stack.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Stack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Stack.dir/flags.make

CMakeFiles/Stack.dir/driver.c.obj: CMakeFiles/Stack.dir/flags.make
CMakeFiles/Stack.dir/driver.c.obj: ../driver.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\voch1\CLionProjects\Stack\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Stack.dir/driver.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Stack.dir\driver.c.obj   -c C:\Users\voch1\CLionProjects\Stack\driver.c

CMakeFiles/Stack.dir/driver.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Stack.dir/driver.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\voch1\CLionProjects\Stack\driver.c > CMakeFiles\Stack.dir\driver.c.i

CMakeFiles/Stack.dir/driver.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Stack.dir/driver.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\voch1\CLionProjects\Stack\driver.c -o CMakeFiles\Stack.dir\driver.c.s

CMakeFiles/Stack.dir/stack312_arr.c.obj: CMakeFiles/Stack.dir/flags.make
CMakeFiles/Stack.dir/stack312_arr.c.obj: ../stack312_arr.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\voch1\CLionProjects\Stack\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Stack.dir/stack312_arr.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Stack.dir\stack312_arr.c.obj   -c C:\Users\voch1\CLionProjects\Stack\stack312_arr.c

CMakeFiles/Stack.dir/stack312_arr.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Stack.dir/stack312_arr.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\voch1\CLionProjects\Stack\stack312_arr.c > CMakeFiles\Stack.dir\stack312_arr.c.i

CMakeFiles/Stack.dir/stack312_arr.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Stack.dir/stack312_arr.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\voch1\CLionProjects\Stack\stack312_arr.c -o CMakeFiles\Stack.dir\stack312_arr.c.s

# Object files for target Stack
Stack_OBJECTS = \
"CMakeFiles/Stack.dir/driver.c.obj" \
"CMakeFiles/Stack.dir/stack312_arr.c.obj"

# External object files for target Stack
Stack_EXTERNAL_OBJECTS =

Stack.exe: CMakeFiles/Stack.dir/driver.c.obj
Stack.exe: CMakeFiles/Stack.dir/stack312_arr.c.obj
Stack.exe: CMakeFiles/Stack.dir/build.make
Stack.exe: CMakeFiles/Stack.dir/linklibs.rsp
Stack.exe: CMakeFiles/Stack.dir/objects1.rsp
Stack.exe: CMakeFiles/Stack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\voch1\CLionProjects\Stack\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Stack.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Stack.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Stack.dir/build: Stack.exe

.PHONY : CMakeFiles/Stack.dir/build

CMakeFiles/Stack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Stack.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Stack.dir/clean

CMakeFiles/Stack.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\voch1\CLionProjects\Stack C:\Users\voch1\CLionProjects\Stack C:\Users\voch1\CLionProjects\Stack\cmake-build-debug C:\Users\voch1\CLionProjects\Stack\cmake-build-debug C:\Users\voch1\CLionProjects\Stack\cmake-build-debug\CMakeFiles\Stack.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Stack.dir/depend
