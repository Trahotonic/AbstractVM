# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rkyslyy/CLionProjects/abstractVM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rkyslyy/CLionProjects/abstractVM/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/abstractVM.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/abstractVM.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/abstractVM.dir/flags.make

CMakeFiles/abstractVM.dir/src/main.cpp.o: CMakeFiles/abstractVM.dir/flags.make
CMakeFiles/abstractVM.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rkyslyy/CLionProjects/abstractVM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/abstractVM.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/abstractVM.dir/src/main.cpp.o -c /Users/rkyslyy/CLionProjects/abstractVM/src/main.cpp

CMakeFiles/abstractVM.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/abstractVM.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rkyslyy/CLionProjects/abstractVM/src/main.cpp > CMakeFiles/abstractVM.dir/src/main.cpp.i

CMakeFiles/abstractVM.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/abstractVM.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rkyslyy/CLionProjects/abstractVM/src/main.cpp -o CMakeFiles/abstractVM.dir/src/main.cpp.s

CMakeFiles/abstractVM.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/abstractVM.dir/src/main.cpp.o.requires

CMakeFiles/abstractVM.dir/src/main.cpp.o.provides: CMakeFiles/abstractVM.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/abstractVM.dir/build.make CMakeFiles/abstractVM.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/abstractVM.dir/src/main.cpp.o.provides

CMakeFiles/abstractVM.dir/src/main.cpp.o.provides.build: CMakeFiles/abstractVM.dir/src/main.cpp.o


CMakeFiles/abstractVM.dir/src/Operand.cpp.o: CMakeFiles/abstractVM.dir/flags.make
CMakeFiles/abstractVM.dir/src/Operand.cpp.o: ../src/Operand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rkyslyy/CLionProjects/abstractVM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/abstractVM.dir/src/Operand.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/abstractVM.dir/src/Operand.cpp.o -c /Users/rkyslyy/CLionProjects/abstractVM/src/Operand.cpp

CMakeFiles/abstractVM.dir/src/Operand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/abstractVM.dir/src/Operand.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rkyslyy/CLionProjects/abstractVM/src/Operand.cpp > CMakeFiles/abstractVM.dir/src/Operand.cpp.i

CMakeFiles/abstractVM.dir/src/Operand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/abstractVM.dir/src/Operand.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rkyslyy/CLionProjects/abstractVM/src/Operand.cpp -o CMakeFiles/abstractVM.dir/src/Operand.cpp.s

CMakeFiles/abstractVM.dir/src/Operand.cpp.o.requires:

.PHONY : CMakeFiles/abstractVM.dir/src/Operand.cpp.o.requires

CMakeFiles/abstractVM.dir/src/Operand.cpp.o.provides: CMakeFiles/abstractVM.dir/src/Operand.cpp.o.requires
	$(MAKE) -f CMakeFiles/abstractVM.dir/build.make CMakeFiles/abstractVM.dir/src/Operand.cpp.o.provides.build
.PHONY : CMakeFiles/abstractVM.dir/src/Operand.cpp.o.provides

CMakeFiles/abstractVM.dir/src/Operand.cpp.o.provides.build: CMakeFiles/abstractVM.dir/src/Operand.cpp.o


CMakeFiles/abstractVM.dir/src/VM.cpp.o: CMakeFiles/abstractVM.dir/flags.make
CMakeFiles/abstractVM.dir/src/VM.cpp.o: ../src/VM.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rkyslyy/CLionProjects/abstractVM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/abstractVM.dir/src/VM.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/abstractVM.dir/src/VM.cpp.o -c /Users/rkyslyy/CLionProjects/abstractVM/src/VM.cpp

CMakeFiles/abstractVM.dir/src/VM.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/abstractVM.dir/src/VM.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rkyslyy/CLionProjects/abstractVM/src/VM.cpp > CMakeFiles/abstractVM.dir/src/VM.cpp.i

CMakeFiles/abstractVM.dir/src/VM.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/abstractVM.dir/src/VM.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rkyslyy/CLionProjects/abstractVM/src/VM.cpp -o CMakeFiles/abstractVM.dir/src/VM.cpp.s

CMakeFiles/abstractVM.dir/src/VM.cpp.o.requires:

.PHONY : CMakeFiles/abstractVM.dir/src/VM.cpp.o.requires

CMakeFiles/abstractVM.dir/src/VM.cpp.o.provides: CMakeFiles/abstractVM.dir/src/VM.cpp.o.requires
	$(MAKE) -f CMakeFiles/abstractVM.dir/build.make CMakeFiles/abstractVM.dir/src/VM.cpp.o.provides.build
.PHONY : CMakeFiles/abstractVM.dir/src/VM.cpp.o.provides

CMakeFiles/abstractVM.dir/src/VM.cpp.o.provides.build: CMakeFiles/abstractVM.dir/src/VM.cpp.o


# Object files for target abstractVM
abstractVM_OBJECTS = \
"CMakeFiles/abstractVM.dir/src/main.cpp.o" \
"CMakeFiles/abstractVM.dir/src/Operand.cpp.o" \
"CMakeFiles/abstractVM.dir/src/VM.cpp.o"

# External object files for target abstractVM
abstractVM_EXTERNAL_OBJECTS =

abstractVM: CMakeFiles/abstractVM.dir/src/main.cpp.o
abstractVM: CMakeFiles/abstractVM.dir/src/Operand.cpp.o
abstractVM: CMakeFiles/abstractVM.dir/src/VM.cpp.o
abstractVM: CMakeFiles/abstractVM.dir/build.make
abstractVM: CMakeFiles/abstractVM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rkyslyy/CLionProjects/abstractVM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable abstractVM"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/abstractVM.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/abstractVM.dir/build: abstractVM

.PHONY : CMakeFiles/abstractVM.dir/build

CMakeFiles/abstractVM.dir/requires: CMakeFiles/abstractVM.dir/src/main.cpp.o.requires
CMakeFiles/abstractVM.dir/requires: CMakeFiles/abstractVM.dir/src/Operand.cpp.o.requires
CMakeFiles/abstractVM.dir/requires: CMakeFiles/abstractVM.dir/src/VM.cpp.o.requires

.PHONY : CMakeFiles/abstractVM.dir/requires

CMakeFiles/abstractVM.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/abstractVM.dir/cmake_clean.cmake
.PHONY : CMakeFiles/abstractVM.dir/clean

CMakeFiles/abstractVM.dir/depend:
	cd /Users/rkyslyy/CLionProjects/abstractVM/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rkyslyy/CLionProjects/abstractVM /Users/rkyslyy/CLionProjects/abstractVM /Users/rkyslyy/CLionProjects/abstractVM/cmake-build-debug /Users/rkyslyy/CLionProjects/abstractVM/cmake-build-debug /Users/rkyslyy/CLionProjects/abstractVM/cmake-build-debug/CMakeFiles/abstractVM.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/abstractVM.dir/depend
