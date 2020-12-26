# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /opt/cmake-3.18.1-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /opt/cmake-3.18.1-Linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ravit/Documents/emulatorProject/Z80/z80Emulation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ravit/Documents/emulatorProject/Z80/z80Emulation

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/opt/cmake-3.18.1-Linux-x86_64/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/opt/cmake-3.18.1-Linux-x86_64/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/ravit/Documents/emulatorProject/Z80/z80Emulation/CMakeFiles /home/ravit/Documents/emulatorProject/Z80/z80Emulation//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/ravit/Documents/emulatorProject/Z80/z80Emulation/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named a.exe

# Build rule for target.
a.exe: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 a.exe
.PHONY : a.exe

# fast build rule for target.
a.exe/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/a.exe.dir/build.make CMakeFiles/a.exe.dir/build
.PHONY : a.exe/fast

src/dataBus.o: src/dataBus.cpp.o

.PHONY : src/dataBus.o

# target to build an object file
src/dataBus.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/a.exe.dir/build.make CMakeFiles/a.exe.dir/src/dataBus.cpp.o
.PHONY : src/dataBus.cpp.o

src/dataBus.i: src/dataBus.cpp.i

.PHONY : src/dataBus.i

# target to preprocess a source file
src/dataBus.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/a.exe.dir/build.make CMakeFiles/a.exe.dir/src/dataBus.cpp.i
.PHONY : src/dataBus.cpp.i

src/dataBus.s: src/dataBus.cpp.s

.PHONY : src/dataBus.s

# target to generate assembly for a file
src/dataBus.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/a.exe.dir/build.make CMakeFiles/a.exe.dir/src/dataBus.cpp.s
.PHONY : src/dataBus.cpp.s

src/emulate.o: src/emulate.cpp.o

.PHONY : src/emulate.o

# target to build an object file
src/emulate.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/a.exe.dir/build.make CMakeFiles/a.exe.dir/src/emulate.cpp.o
.PHONY : src/emulate.cpp.o

src/emulate.i: src/emulate.cpp.i

.PHONY : src/emulate.i

# target to preprocess a source file
src/emulate.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/a.exe.dir/build.make CMakeFiles/a.exe.dir/src/emulate.cpp.i
.PHONY : src/emulate.cpp.i

src/emulate.s: src/emulate.cpp.s

.PHONY : src/emulate.s

# target to generate assembly for a file
src/emulate.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/a.exe.dir/build.make CMakeFiles/a.exe.dir/src/emulate.cpp.s
.PHONY : src/emulate.cpp.s

src/machine.o: src/machine.cpp.o

.PHONY : src/machine.o

# target to build an object file
src/machine.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/a.exe.dir/build.make CMakeFiles/a.exe.dir/src/machine.cpp.o
.PHONY : src/machine.cpp.o

src/machine.i: src/machine.cpp.i

.PHONY : src/machine.i

# target to preprocess a source file
src/machine.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/a.exe.dir/build.make CMakeFiles/a.exe.dir/src/machine.cpp.i
.PHONY : src/machine.cpp.i

src/machine.s: src/machine.cpp.s

.PHONY : src/machine.s

# target to generate assembly for a file
src/machine.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/a.exe.dir/build.make CMakeFiles/a.exe.dir/src/machine.cpp.s
.PHONY : src/machine.cpp.s

src/memory.o: src/memory.cpp.o

.PHONY : src/memory.o

# target to build an object file
src/memory.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/a.exe.dir/build.make CMakeFiles/a.exe.dir/src/memory.cpp.o
.PHONY : src/memory.cpp.o

src/memory.i: src/memory.cpp.i

.PHONY : src/memory.i

# target to preprocess a source file
src/memory.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/a.exe.dir/build.make CMakeFiles/a.exe.dir/src/memory.cpp.i
.PHONY : src/memory.cpp.i

src/memory.s: src/memory.cpp.s

.PHONY : src/memory.s

# target to generate assembly for a file
src/memory.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/a.exe.dir/build.make CMakeFiles/a.exe.dir/src/memory.cpp.s
.PHONY : src/memory.cpp.s

src/module.o: src/module.cpp.o

.PHONY : src/module.o

# target to build an object file
src/module.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/a.exe.dir/build.make CMakeFiles/a.exe.dir/src/module.cpp.o
.PHONY : src/module.cpp.o

src/module.i: src/module.cpp.i

.PHONY : src/module.i

# target to preprocess a source file
src/module.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/a.exe.dir/build.make CMakeFiles/a.exe.dir/src/module.cpp.i
.PHONY : src/module.cpp.i

src/module.s: src/module.cpp.s

.PHONY : src/module.s

# target to generate assembly for a file
src/module.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/a.exe.dir/build.make CMakeFiles/a.exe.dir/src/module.cpp.s
.PHONY : src/module.cpp.s

src/z80CPU.o: src/z80CPU.cpp.o

.PHONY : src/z80CPU.o

# target to build an object file
src/z80CPU.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/a.exe.dir/build.make CMakeFiles/a.exe.dir/src/z80CPU.cpp.o
.PHONY : src/z80CPU.cpp.o

src/z80CPU.i: src/z80CPU.cpp.i

.PHONY : src/z80CPU.i

# target to preprocess a source file
src/z80CPU.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/a.exe.dir/build.make CMakeFiles/a.exe.dir/src/z80CPU.cpp.i
.PHONY : src/z80CPU.cpp.i

src/z80CPU.s: src/z80CPU.cpp.s

.PHONY : src/z80CPU.s

# target to generate assembly for a file
src/z80CPU.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/a.exe.dir/build.make CMakeFiles/a.exe.dir/src/z80CPU.cpp.s
.PHONY : src/z80CPU.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... a.exe"
	@echo "... src/dataBus.o"
	@echo "... src/dataBus.i"
	@echo "... src/dataBus.s"
	@echo "... src/emulate.o"
	@echo "... src/emulate.i"
	@echo "... src/emulate.s"
	@echo "... src/machine.o"
	@echo "... src/machine.i"
	@echo "... src/machine.s"
	@echo "... src/memory.o"
	@echo "... src/memory.i"
	@echo "... src/memory.s"
	@echo "... src/module.o"
	@echo "... src/module.i"
	@echo "... src/module.s"
	@echo "... src/z80CPU.o"
	@echo "... src/z80CPU.i"
	@echo "... src/z80CPU.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

