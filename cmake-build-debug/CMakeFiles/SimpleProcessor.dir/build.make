# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/ivanbrekman/programms/clion-2021.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/ivanbrekman/programms/clion-2021.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ivanbrekman/CLionProjects/SimpleProcessor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ivanbrekman/CLionProjects/SimpleProcessor/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SimpleProcessor.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/SimpleProcessor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SimpleProcessor.dir/flags.make

CMakeFiles/SimpleProcessor.dir/main.cpp.o: CMakeFiles/SimpleProcessor.dir/flags.make
CMakeFiles/SimpleProcessor.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivanbrekman/CLionProjects/SimpleProcessor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SimpleProcessor.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleProcessor.dir/main.cpp.o -c /home/ivanbrekman/CLionProjects/SimpleProcessor/main.cpp

CMakeFiles/SimpleProcessor.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleProcessor.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivanbrekman/CLionProjects/SimpleProcessor/main.cpp > CMakeFiles/SimpleProcessor.dir/main.cpp.i

CMakeFiles/SimpleProcessor.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleProcessor.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivanbrekman/CLionProjects/SimpleProcessor/main.cpp -o CMakeFiles/SimpleProcessor.dir/main.cpp.s

CMakeFiles/SimpleProcessor.dir/processor.cpp.o: CMakeFiles/SimpleProcessor.dir/flags.make
CMakeFiles/SimpleProcessor.dir/processor.cpp.o: ../processor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivanbrekman/CLionProjects/SimpleProcessor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SimpleProcessor.dir/processor.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleProcessor.dir/processor.cpp.o -c /home/ivanbrekman/CLionProjects/SimpleProcessor/processor.cpp

CMakeFiles/SimpleProcessor.dir/processor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleProcessor.dir/processor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivanbrekman/CLionProjects/SimpleProcessor/processor.cpp > CMakeFiles/SimpleProcessor.dir/processor.cpp.i

CMakeFiles/SimpleProcessor.dir/processor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleProcessor.dir/processor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivanbrekman/CLionProjects/SimpleProcessor/processor.cpp -o CMakeFiles/SimpleProcessor.dir/processor.cpp.s

CMakeFiles/SimpleProcessor.dir/compiler.cpp.o: CMakeFiles/SimpleProcessor.dir/flags.make
CMakeFiles/SimpleProcessor.dir/compiler.cpp.o: ../compiler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivanbrekman/CLionProjects/SimpleProcessor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SimpleProcessor.dir/compiler.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleProcessor.dir/compiler.cpp.o -c /home/ivanbrekman/CLionProjects/SimpleProcessor/compiler.cpp

CMakeFiles/SimpleProcessor.dir/compiler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleProcessor.dir/compiler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivanbrekman/CLionProjects/SimpleProcessor/compiler.cpp > CMakeFiles/SimpleProcessor.dir/compiler.cpp.i

CMakeFiles/SimpleProcessor.dir/compiler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleProcessor.dir/compiler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivanbrekman/CLionProjects/SimpleProcessor/compiler.cpp -o CMakeFiles/SimpleProcessor.dir/compiler.cpp.s

CMakeFiles/SimpleProcessor.dir/asm/asm.cpp.o: CMakeFiles/SimpleProcessor.dir/flags.make
CMakeFiles/SimpleProcessor.dir/asm/asm.cpp.o: ../asm/asm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivanbrekman/CLionProjects/SimpleProcessor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SimpleProcessor.dir/asm/asm.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleProcessor.dir/asm/asm.cpp.o -c /home/ivanbrekman/CLionProjects/SimpleProcessor/asm/asm.cpp

CMakeFiles/SimpleProcessor.dir/asm/asm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleProcessor.dir/asm/asm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivanbrekman/CLionProjects/SimpleProcessor/asm/asm.cpp > CMakeFiles/SimpleProcessor.dir/asm/asm.cpp.i

CMakeFiles/SimpleProcessor.dir/asm/asm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleProcessor.dir/asm/asm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivanbrekman/CLionProjects/SimpleProcessor/asm/asm.cpp -o CMakeFiles/SimpleProcessor.dir/asm/asm.cpp.s

CMakeFiles/SimpleProcessor.dir/CPU/cpu.cpp.o: CMakeFiles/SimpleProcessor.dir/flags.make
CMakeFiles/SimpleProcessor.dir/CPU/cpu.cpp.o: ../CPU/cpu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivanbrekman/CLionProjects/SimpleProcessor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SimpleProcessor.dir/CPU/cpu.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleProcessor.dir/CPU/cpu.cpp.o -c /home/ivanbrekman/CLionProjects/SimpleProcessor/CPU/cpu.cpp

CMakeFiles/SimpleProcessor.dir/CPU/cpu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleProcessor.dir/CPU/cpu.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivanbrekman/CLionProjects/SimpleProcessor/CPU/cpu.cpp > CMakeFiles/SimpleProcessor.dir/CPU/cpu.cpp.i

CMakeFiles/SimpleProcessor.dir/CPU/cpu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleProcessor.dir/CPU/cpu.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivanbrekman/CLionProjects/SimpleProcessor/CPU/cpu.cpp -o CMakeFiles/SimpleProcessor.dir/CPU/cpu.cpp.s

CMakeFiles/SimpleProcessor.dir/dis/dis.cpp.o: CMakeFiles/SimpleProcessor.dir/flags.make
CMakeFiles/SimpleProcessor.dir/dis/dis.cpp.o: ../dis/dis.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivanbrekman/CLionProjects/SimpleProcessor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SimpleProcessor.dir/dis/dis.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleProcessor.dir/dis/dis.cpp.o -c /home/ivanbrekman/CLionProjects/SimpleProcessor/dis/dis.cpp

CMakeFiles/SimpleProcessor.dir/dis/dis.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleProcessor.dir/dis/dis.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivanbrekman/CLionProjects/SimpleProcessor/dis/dis.cpp > CMakeFiles/SimpleProcessor.dir/dis/dis.cpp.i

CMakeFiles/SimpleProcessor.dir/dis/dis.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleProcessor.dir/dis/dis.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivanbrekman/CLionProjects/SimpleProcessor/dis/dis.cpp -o CMakeFiles/SimpleProcessor.dir/dis/dis.cpp.s

CMakeFiles/SimpleProcessor.dir/helper.cpp.o: CMakeFiles/SimpleProcessor.dir/flags.make
CMakeFiles/SimpleProcessor.dir/helper.cpp.o: ../helper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivanbrekman/CLionProjects/SimpleProcessor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/SimpleProcessor.dir/helper.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleProcessor.dir/helper.cpp.o -c /home/ivanbrekman/CLionProjects/SimpleProcessor/helper.cpp

CMakeFiles/SimpleProcessor.dir/helper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleProcessor.dir/helper.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivanbrekman/CLionProjects/SimpleProcessor/helper.cpp > CMakeFiles/SimpleProcessor.dir/helper.cpp.i

CMakeFiles/SimpleProcessor.dir/helper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleProcessor.dir/helper.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivanbrekman/CLionProjects/SimpleProcessor/helper.cpp -o CMakeFiles/SimpleProcessor.dir/helper.cpp.s

CMakeFiles/SimpleProcessor.dir/libs/file_funcs.cpp.o: CMakeFiles/SimpleProcessor.dir/flags.make
CMakeFiles/SimpleProcessor.dir/libs/file_funcs.cpp.o: ../libs/file_funcs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivanbrekman/CLionProjects/SimpleProcessor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/SimpleProcessor.dir/libs/file_funcs.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleProcessor.dir/libs/file_funcs.cpp.o -c /home/ivanbrekman/CLionProjects/SimpleProcessor/libs/file_funcs.cpp

CMakeFiles/SimpleProcessor.dir/libs/file_funcs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleProcessor.dir/libs/file_funcs.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivanbrekman/CLionProjects/SimpleProcessor/libs/file_funcs.cpp > CMakeFiles/SimpleProcessor.dir/libs/file_funcs.cpp.i

CMakeFiles/SimpleProcessor.dir/libs/file_funcs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleProcessor.dir/libs/file_funcs.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivanbrekman/CLionProjects/SimpleProcessor/libs/file_funcs.cpp -o CMakeFiles/SimpleProcessor.dir/libs/file_funcs.cpp.s

CMakeFiles/SimpleProcessor.dir/libs/stack.cpp.o: CMakeFiles/SimpleProcessor.dir/flags.make
CMakeFiles/SimpleProcessor.dir/libs/stack.cpp.o: ../libs/stack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivanbrekman/CLionProjects/SimpleProcessor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/SimpleProcessor.dir/libs/stack.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleProcessor.dir/libs/stack.cpp.o -c /home/ivanbrekman/CLionProjects/SimpleProcessor/libs/stack.cpp

CMakeFiles/SimpleProcessor.dir/libs/stack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleProcessor.dir/libs/stack.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivanbrekman/CLionProjects/SimpleProcessor/libs/stack.cpp > CMakeFiles/SimpleProcessor.dir/libs/stack.cpp.i

CMakeFiles/SimpleProcessor.dir/libs/stack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleProcessor.dir/libs/stack.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivanbrekman/CLionProjects/SimpleProcessor/libs/stack.cpp -o CMakeFiles/SimpleProcessor.dir/libs/stack.cpp.s

CMakeFiles/SimpleProcessor.dir/libs/baselib.cpp.o: CMakeFiles/SimpleProcessor.dir/flags.make
CMakeFiles/SimpleProcessor.dir/libs/baselib.cpp.o: ../libs/baselib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivanbrekman/CLionProjects/SimpleProcessor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/SimpleProcessor.dir/libs/baselib.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleProcessor.dir/libs/baselib.cpp.o -c /home/ivanbrekman/CLionProjects/SimpleProcessor/libs/baselib.cpp

CMakeFiles/SimpleProcessor.dir/libs/baselib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleProcessor.dir/libs/baselib.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivanbrekman/CLionProjects/SimpleProcessor/libs/baselib.cpp > CMakeFiles/SimpleProcessor.dir/libs/baselib.cpp.i

CMakeFiles/SimpleProcessor.dir/libs/baselib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleProcessor.dir/libs/baselib.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivanbrekman/CLionProjects/SimpleProcessor/libs/baselib.cpp -o CMakeFiles/SimpleProcessor.dir/libs/baselib.cpp.s

CMakeFiles/SimpleProcessor.dir/tests/baselib_test.cpp.o: CMakeFiles/SimpleProcessor.dir/flags.make
CMakeFiles/SimpleProcessor.dir/tests/baselib_test.cpp.o: ../tests/baselib_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivanbrekman/CLionProjects/SimpleProcessor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/SimpleProcessor.dir/tests/baselib_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleProcessor.dir/tests/baselib_test.cpp.o -c /home/ivanbrekman/CLionProjects/SimpleProcessor/tests/baselib_test.cpp

CMakeFiles/SimpleProcessor.dir/tests/baselib_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleProcessor.dir/tests/baselib_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivanbrekman/CLionProjects/SimpleProcessor/tests/baselib_test.cpp > CMakeFiles/SimpleProcessor.dir/tests/baselib_test.cpp.i

CMakeFiles/SimpleProcessor.dir/tests/baselib_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleProcessor.dir/tests/baselib_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivanbrekman/CLionProjects/SimpleProcessor/tests/baselib_test.cpp -o CMakeFiles/SimpleProcessor.dir/tests/baselib_test.cpp.s

# Object files for target SimpleProcessor
SimpleProcessor_OBJECTS = \
"CMakeFiles/SimpleProcessor.dir/main.cpp.o" \
"CMakeFiles/SimpleProcessor.dir/processor.cpp.o" \
"CMakeFiles/SimpleProcessor.dir/compiler.cpp.o" \
"CMakeFiles/SimpleProcessor.dir/asm/asm.cpp.o" \
"CMakeFiles/SimpleProcessor.dir/CPU/cpu.cpp.o" \
"CMakeFiles/SimpleProcessor.dir/dis/dis.cpp.o" \
"CMakeFiles/SimpleProcessor.dir/helper.cpp.o" \
"CMakeFiles/SimpleProcessor.dir/libs/file_funcs.cpp.o" \
"CMakeFiles/SimpleProcessor.dir/libs/stack.cpp.o" \
"CMakeFiles/SimpleProcessor.dir/libs/baselib.cpp.o" \
"CMakeFiles/SimpleProcessor.dir/tests/baselib_test.cpp.o"

# External object files for target SimpleProcessor
SimpleProcessor_EXTERNAL_OBJECTS =

SimpleProcessor: CMakeFiles/SimpleProcessor.dir/main.cpp.o
SimpleProcessor: CMakeFiles/SimpleProcessor.dir/processor.cpp.o
SimpleProcessor: CMakeFiles/SimpleProcessor.dir/compiler.cpp.o
SimpleProcessor: CMakeFiles/SimpleProcessor.dir/asm/asm.cpp.o
SimpleProcessor: CMakeFiles/SimpleProcessor.dir/CPU/cpu.cpp.o
SimpleProcessor: CMakeFiles/SimpleProcessor.dir/dis/dis.cpp.o
SimpleProcessor: CMakeFiles/SimpleProcessor.dir/helper.cpp.o
SimpleProcessor: CMakeFiles/SimpleProcessor.dir/libs/file_funcs.cpp.o
SimpleProcessor: CMakeFiles/SimpleProcessor.dir/libs/stack.cpp.o
SimpleProcessor: CMakeFiles/SimpleProcessor.dir/libs/baselib.cpp.o
SimpleProcessor: CMakeFiles/SimpleProcessor.dir/tests/baselib_test.cpp.o
SimpleProcessor: CMakeFiles/SimpleProcessor.dir/build.make
SimpleProcessor: CMakeFiles/SimpleProcessor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ivanbrekman/CLionProjects/SimpleProcessor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable SimpleProcessor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SimpleProcessor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SimpleProcessor.dir/build: SimpleProcessor
.PHONY : CMakeFiles/SimpleProcessor.dir/build

CMakeFiles/SimpleProcessor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SimpleProcessor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SimpleProcessor.dir/clean

CMakeFiles/SimpleProcessor.dir/depend:
	cd /home/ivanbrekman/CLionProjects/SimpleProcessor/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ivanbrekman/CLionProjects/SimpleProcessor /home/ivanbrekman/CLionProjects/SimpleProcessor /home/ivanbrekman/CLionProjects/SimpleProcessor/cmake-build-debug /home/ivanbrekman/CLionProjects/SimpleProcessor/cmake-build-debug /home/ivanbrekman/CLionProjects/SimpleProcessor/cmake-build-debug/CMakeFiles/SimpleProcessor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SimpleProcessor.dir/depend

