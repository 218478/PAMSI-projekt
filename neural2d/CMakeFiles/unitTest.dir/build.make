# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/kkuczaj/PAMSI-projekt/neural2d

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kkuczaj/PAMSI-projekt/neural2d

# Include any dependencies generated for this target.
include CMakeFiles/unitTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/unitTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/unitTest.dir/flags.make

images/digits/test-1.bmp: images/digits/digits.zip
	$(CMAKE_COMMAND) -E cmake_progress_report /home/kkuczaj/PAMSI-projekt/neural2d/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Preparing images/digits/..."
	cd /home/kkuczaj/PAMSI-projekt/neural2d/images/digits && /usr/bin/cmake -E tar xzf /home/kkuczaj/PAMSI-projekt/neural2d/images/digits/digits.zip

CMakeFiles/unitTest.dir/src/unitTest.cpp.o: CMakeFiles/unitTest.dir/flags.make
CMakeFiles/unitTest.dir/src/unitTest.cpp.o: src/unitTest.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/kkuczaj/PAMSI-projekt/neural2d/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/unitTest.dir/src/unitTest.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/unitTest.dir/src/unitTest.cpp.o -c /home/kkuczaj/PAMSI-projekt/neural2d/src/unitTest.cpp

CMakeFiles/unitTest.dir/src/unitTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unitTest.dir/src/unitTest.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/kkuczaj/PAMSI-projekt/neural2d/src/unitTest.cpp > CMakeFiles/unitTest.dir/src/unitTest.cpp.i

CMakeFiles/unitTest.dir/src/unitTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unitTest.dir/src/unitTest.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/kkuczaj/PAMSI-projekt/neural2d/src/unitTest.cpp -o CMakeFiles/unitTest.dir/src/unitTest.cpp.s

CMakeFiles/unitTest.dir/src/unitTest.cpp.o.requires:
.PHONY : CMakeFiles/unitTest.dir/src/unitTest.cpp.o.requires

CMakeFiles/unitTest.dir/src/unitTest.cpp.o.provides: CMakeFiles/unitTest.dir/src/unitTest.cpp.o.requires
	$(MAKE) -f CMakeFiles/unitTest.dir/build.make CMakeFiles/unitTest.dir/src/unitTest.cpp.o.provides.build
.PHONY : CMakeFiles/unitTest.dir/src/unitTest.cpp.o.provides

CMakeFiles/unitTest.dir/src/unitTest.cpp.o.provides.build: CMakeFiles/unitTest.dir/src/unitTest.cpp.o

# Object files for target unitTest
unitTest_OBJECTS = \
"CMakeFiles/unitTest.dir/src/unitTest.cpp.o"

# External object files for target unitTest
unitTest_EXTERNAL_OBJECTS =

unitTest: CMakeFiles/unitTest.dir/src/unitTest.cpp.o
unitTest: CMakeFiles/unitTest.dir/build.make
unitTest: libneural2d-core.a
unitTest: CMakeFiles/unitTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable unitTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unitTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/unitTest.dir/build: unitTest
.PHONY : CMakeFiles/unitTest.dir/build

CMakeFiles/unitTest.dir/requires: CMakeFiles/unitTest.dir/src/unitTest.cpp.o.requires
.PHONY : CMakeFiles/unitTest.dir/requires

CMakeFiles/unitTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/unitTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/unitTest.dir/clean

CMakeFiles/unitTest.dir/depend: images/digits/test-1.bmp
	cd /home/kkuczaj/PAMSI-projekt/neural2d && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kkuczaj/PAMSI-projekt/neural2d /home/kkuczaj/PAMSI-projekt/neural2d /home/kkuczaj/PAMSI-projekt/neural2d /home/kkuczaj/PAMSI-projekt/neural2d /home/kkuczaj/PAMSI-projekt/neural2d/CMakeFiles/unitTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/unitTest.dir/depend

