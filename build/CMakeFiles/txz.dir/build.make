# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.3

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.3.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.3.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/bmulocher/Documents/MPRO/ECMA/Projet/Projet-ECMA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bmulocher/Documents/MPRO/ECMA/Projet/Projet-ECMA/build

# Utility rule file for txz.

# Include the progress variables for this target.
include CMakeFiles/txz.dir/progress.make

CMakeFiles/txz:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/bmulocher/Documents/MPRO/ECMA/Projet/Projet-ECMA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Création d'une archive datée du projet (TEST XZ)"
	@echo " => duplication du projet en : Projet-ECMA-20160306-22h46"
	cp -Rp /Users/bmulocher/Documents/MPRO/ECMA/Projet/Projet-ECMA /Users/bmulocher/Documents/MPRO/ECMA/Projet/Projet-ECMA-20160306-22h46
	rm -r /Users/bmulocher/Documents/MPRO/ECMA/Projet/Projet-ECMA-20160306-22h46/build/
	mkdir -p /Users/bmulocher/Documents/MPRO/ECMA/Projet/Projet-ECMA-20160306-22h46/build/
	tar cf /Users/bmulocher/Documents/MPRO/ECMA/Projet/Projet-ECMA-20160306-22h46.tar -C /Users/bmulocher/Documents/MPRO/ECMA/Projet/Projet-ECMA/.. Projet-ECMA-20160306-22h46
	xz /Users/bmulocher/Documents/MPRO/ECMA/Projet/Projet-ECMA-20160306-22h46.tar
	mv /Users/bmulocher/Documents/MPRO/ECMA/Projet/Projet-ECMA-20160306-22h46.tar.xz /Users/bmulocher/Documents/MPRO/ECMA/Projet/Projet-ECMA-20160306-22h46.txz
	rm -r /Users/bmulocher/Documents/MPRO/ECMA/Projet/Projet-ECMA-20160306-22h46
	@echo " => Archive faite : Projet-ECMA-20160306-22h46.tbz"

txz: CMakeFiles/txz
txz: CMakeFiles/txz.dir/build.make

.PHONY : txz

# Rule to build all files generated by this target.
CMakeFiles/txz.dir/build: txz

.PHONY : CMakeFiles/txz.dir/build

CMakeFiles/txz.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/txz.dir/cmake_clean.cmake
.PHONY : CMakeFiles/txz.dir/clean

CMakeFiles/txz.dir/depend:
	cd /Users/bmulocher/Documents/MPRO/ECMA/Projet/Projet-ECMA/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bmulocher/Documents/MPRO/ECMA/Projet/Projet-ECMA /Users/bmulocher/Documents/MPRO/ECMA/Projet/Projet-ECMA /Users/bmulocher/Documents/MPRO/ECMA/Projet/Projet-ECMA/build /Users/bmulocher/Documents/MPRO/ECMA/Projet/Projet-ECMA/build /Users/bmulocher/Documents/MPRO/ECMA/Projet/Projet-ECMA/build/CMakeFiles/txz.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/txz.dir/depend

