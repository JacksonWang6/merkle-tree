# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\44811\Desktop\lab\bigdata_lab3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\44811\Desktop\lab\bigdata_lab3

# Include any dependencies generated for this target.
include CMakeFiles/bigdata_lab3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bigdata_lab3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bigdata_lab3.dir/flags.make

CMakeFiles/bigdata_lab3.dir/main.c.obj: CMakeFiles/bigdata_lab3.dir/flags.make
CMakeFiles/bigdata_lab3.dir/main.c.obj: main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\44811\Desktop\lab\bigdata_lab3\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/bigdata_lab3.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\bigdata_lab3.dir\main.c.obj   -c C:\Users\44811\Desktop\lab\bigdata_lab3\main.c

CMakeFiles/bigdata_lab3.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bigdata_lab3.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\44811\Desktop\lab\bigdata_lab3\main.c > CMakeFiles\bigdata_lab3.dir\main.c.i

CMakeFiles/bigdata_lab3.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bigdata_lab3.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\44811\Desktop\lab\bigdata_lab3\main.c -o CMakeFiles\bigdata_lab3.dir\main.c.s

CMakeFiles/bigdata_lab3.dir/sha256.c.obj: CMakeFiles/bigdata_lab3.dir/flags.make
CMakeFiles/bigdata_lab3.dir/sha256.c.obj: sha256.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\44811\Desktop\lab\bigdata_lab3\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/bigdata_lab3.dir/sha256.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\bigdata_lab3.dir\sha256.c.obj   -c C:\Users\44811\Desktop\lab\bigdata_lab3\sha256.c

CMakeFiles/bigdata_lab3.dir/sha256.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bigdata_lab3.dir/sha256.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\44811\Desktop\lab\bigdata_lab3\sha256.c > CMakeFiles\bigdata_lab3.dir\sha256.c.i

CMakeFiles/bigdata_lab3.dir/sha256.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bigdata_lab3.dir/sha256.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\44811\Desktop\lab\bigdata_lab3\sha256.c -o CMakeFiles\bigdata_lab3.dir\sha256.c.s

CMakeFiles/bigdata_lab3.dir/mttree.c.obj: CMakeFiles/bigdata_lab3.dir/flags.make
CMakeFiles/bigdata_lab3.dir/mttree.c.obj: mttree.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\44811\Desktop\lab\bigdata_lab3\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/bigdata_lab3.dir/mttree.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\bigdata_lab3.dir\mttree.c.obj   -c C:\Users\44811\Desktop\lab\bigdata_lab3\mttree.c

CMakeFiles/bigdata_lab3.dir/mttree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bigdata_lab3.dir/mttree.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\44811\Desktop\lab\bigdata_lab3\mttree.c > CMakeFiles\bigdata_lab3.dir\mttree.c.i

CMakeFiles/bigdata_lab3.dir/mttree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bigdata_lab3.dir/mttree.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\44811\Desktop\lab\bigdata_lab3\mttree.c -o CMakeFiles\bigdata_lab3.dir\mttree.c.s

CMakeFiles/bigdata_lab3.dir/queue.c.obj: CMakeFiles/bigdata_lab3.dir/flags.make
CMakeFiles/bigdata_lab3.dir/queue.c.obj: queue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\44811\Desktop\lab\bigdata_lab3\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/bigdata_lab3.dir/queue.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\bigdata_lab3.dir\queue.c.obj   -c C:\Users\44811\Desktop\lab\bigdata_lab3\queue.c

CMakeFiles/bigdata_lab3.dir/queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bigdata_lab3.dir/queue.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\44811\Desktop\lab\bigdata_lab3\queue.c > CMakeFiles\bigdata_lab3.dir\queue.c.i

CMakeFiles/bigdata_lab3.dir/queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bigdata_lab3.dir/queue.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\44811\Desktop\lab\bigdata_lab3\queue.c -o CMakeFiles\bigdata_lab3.dir\queue.c.s

# Object files for target bigdata_lab3
bigdata_lab3_OBJECTS = \
"CMakeFiles/bigdata_lab3.dir/main.c.obj" \
"CMakeFiles/bigdata_lab3.dir/sha256.c.obj" \
"CMakeFiles/bigdata_lab3.dir/mttree.c.obj" \
"CMakeFiles/bigdata_lab3.dir/queue.c.obj"

# External object files for target bigdata_lab3
bigdata_lab3_EXTERNAL_OBJECTS =

bigdata_lab3.exe: CMakeFiles/bigdata_lab3.dir/main.c.obj
bigdata_lab3.exe: CMakeFiles/bigdata_lab3.dir/sha256.c.obj
bigdata_lab3.exe: CMakeFiles/bigdata_lab3.dir/mttree.c.obj
bigdata_lab3.exe: CMakeFiles/bigdata_lab3.dir/queue.c.obj
bigdata_lab3.exe: CMakeFiles/bigdata_lab3.dir/build.make
bigdata_lab3.exe: CMakeFiles/bigdata_lab3.dir/linklibs.rsp
bigdata_lab3.exe: CMakeFiles/bigdata_lab3.dir/objects1.rsp
bigdata_lab3.exe: CMakeFiles/bigdata_lab3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\44811\Desktop\lab\bigdata_lab3\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable bigdata_lab3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\bigdata_lab3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bigdata_lab3.dir/build: bigdata_lab3.exe

.PHONY : CMakeFiles/bigdata_lab3.dir/build

CMakeFiles/bigdata_lab3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\bigdata_lab3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/bigdata_lab3.dir/clean

CMakeFiles/bigdata_lab3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\44811\Desktop\lab\bigdata_lab3 C:\Users\44811\Desktop\lab\bigdata_lab3 C:\Users\44811\Desktop\lab\bigdata_lab3 C:\Users\44811\Desktop\lab\bigdata_lab3 C:\Users\44811\Desktop\lab\bigdata_lab3\CMakeFiles\bigdata_lab3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bigdata_lab3.dir/depend
