# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/pi/Documents/sound_manager/libsoundio

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/Documents/sound_manager/libsoundio/build

# Include any dependencies generated for this target.
include CMakeFiles/sio_record.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sio_record.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sio_record.dir/flags.make

CMakeFiles/sio_record.dir/example/sio_record.c.o: CMakeFiles/sio_record.dir/flags.make
CMakeFiles/sio_record.dir/example/sio_record.c.o: ../example/sio_record.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Documents/sound_manager/libsoundio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sio_record.dir/example/sio_record.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sio_record.dir/example/sio_record.c.o   -c /home/pi/Documents/sound_manager/libsoundio/example/sio_record.c

CMakeFiles/sio_record.dir/example/sio_record.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sio_record.dir/example/sio_record.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/Documents/sound_manager/libsoundio/example/sio_record.c > CMakeFiles/sio_record.dir/example/sio_record.c.i

CMakeFiles/sio_record.dir/example/sio_record.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sio_record.dir/example/sio_record.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/Documents/sound_manager/libsoundio/example/sio_record.c -o CMakeFiles/sio_record.dir/example/sio_record.c.s

CMakeFiles/sio_record.dir/example/sio_record.c.o.requires:

.PHONY : CMakeFiles/sio_record.dir/example/sio_record.c.o.requires

CMakeFiles/sio_record.dir/example/sio_record.c.o.provides: CMakeFiles/sio_record.dir/example/sio_record.c.o.requires
	$(MAKE) -f CMakeFiles/sio_record.dir/build.make CMakeFiles/sio_record.dir/example/sio_record.c.o.provides.build
.PHONY : CMakeFiles/sio_record.dir/example/sio_record.c.o.provides

CMakeFiles/sio_record.dir/example/sio_record.c.o.provides.build: CMakeFiles/sio_record.dir/example/sio_record.c.o


# Object files for target sio_record
sio_record_OBJECTS = \
"CMakeFiles/sio_record.dir/example/sio_record.c.o"

# External object files for target sio_record
sio_record_EXTERNAL_OBJECTS =

sio_record: CMakeFiles/sio_record.dir/example/sio_record.c.o
sio_record: CMakeFiles/sio_record.dir/build.make
sio_record: libsoundio.so.1.1.0
sio_record: /usr/lib/arm-linux-gnueabihf/libpulse.so
sio_record: CMakeFiles/sio_record.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/Documents/sound_manager/libsoundio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable sio_record"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sio_record.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sio_record.dir/build: sio_record

.PHONY : CMakeFiles/sio_record.dir/build

CMakeFiles/sio_record.dir/requires: CMakeFiles/sio_record.dir/example/sio_record.c.o.requires

.PHONY : CMakeFiles/sio_record.dir/requires

CMakeFiles/sio_record.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sio_record.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sio_record.dir/clean

CMakeFiles/sio_record.dir/depend:
	cd /home/pi/Documents/sound_manager/libsoundio/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Documents/sound_manager/libsoundio /home/pi/Documents/sound_manager/libsoundio /home/pi/Documents/sound_manager/libsoundio/build /home/pi/Documents/sound_manager/libsoundio/build /home/pi/Documents/sound_manager/libsoundio/build/CMakeFiles/sio_record.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sio_record.dir/depend

