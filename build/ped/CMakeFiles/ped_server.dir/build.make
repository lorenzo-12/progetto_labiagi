# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/me/progetto_labiagi/src/ped

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/me/progetto_labiagi/build/ped

# Include any dependencies generated for this target.
include CMakeFiles/ped_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ped_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ped_server.dir/flags.make

CMakeFiles/ped_server.dir/src/ped_server.cpp.o: CMakeFiles/ped_server.dir/flags.make
CMakeFiles/ped_server.dir/src/ped_server.cpp.o: /home/me/progetto_labiagi/src/ped/src/ped_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/me/progetto_labiagi/build/ped/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ped_server.dir/src/ped_server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ped_server.dir/src/ped_server.cpp.o -c /home/me/progetto_labiagi/src/ped/src/ped_server.cpp

CMakeFiles/ped_server.dir/src/ped_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ped_server.dir/src/ped_server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/me/progetto_labiagi/src/ped/src/ped_server.cpp > CMakeFiles/ped_server.dir/src/ped_server.cpp.i

CMakeFiles/ped_server.dir/src/ped_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ped_server.dir/src/ped_server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/me/progetto_labiagi/src/ped/src/ped_server.cpp -o CMakeFiles/ped_server.dir/src/ped_server.cpp.s

CMakeFiles/ped_server.dir/src/ped_server.cpp.o.requires:

.PHONY : CMakeFiles/ped_server.dir/src/ped_server.cpp.o.requires

CMakeFiles/ped_server.dir/src/ped_server.cpp.o.provides: CMakeFiles/ped_server.dir/src/ped_server.cpp.o.requires
	$(MAKE) -f CMakeFiles/ped_server.dir/build.make CMakeFiles/ped_server.dir/src/ped_server.cpp.o.provides.build
.PHONY : CMakeFiles/ped_server.dir/src/ped_server.cpp.o.provides

CMakeFiles/ped_server.dir/src/ped_server.cpp.o.provides.build: CMakeFiles/ped_server.dir/src/ped_server.cpp.o


# Object files for target ped_server
ped_server_OBJECTS = \
"CMakeFiles/ped_server.dir/src/ped_server.cpp.o"

# External object files for target ped_server
ped_server_EXTERNAL_OBJECTS =

/home/me/progetto_labiagi/devel/.private/ped/lib/ped/ped_server: CMakeFiles/ped_server.dir/src/ped_server.cpp.o
/home/me/progetto_labiagi/devel/.private/ped/lib/ped/ped_server: CMakeFiles/ped_server.dir/build.make
/home/me/progetto_labiagi/devel/.private/ped/lib/ped/ped_server: /opt/ros/melodic/lib/libroscpp.so
/home/me/progetto_labiagi/devel/.private/ped/lib/ped/ped_server: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/me/progetto_labiagi/devel/.private/ped/lib/ped/ped_server: /opt/ros/melodic/lib/librosconsole.so
/home/me/progetto_labiagi/devel/.private/ped/lib/ped/ped_server: /opt/ros/melodic/lib/librosconsole_log4cxx.so
/home/me/progetto_labiagi/devel/.private/ped/lib/ped/ped_server: /opt/ros/melodic/lib/librosconsole_backend_interface.so
/home/me/progetto_labiagi/devel/.private/ped/lib/ped/ped_server: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/me/progetto_labiagi/devel/.private/ped/lib/ped/ped_server: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/me/progetto_labiagi/devel/.private/ped/lib/ped/ped_server: /opt/ros/melodic/lib/libxmlrpcpp.so
/home/me/progetto_labiagi/devel/.private/ped/lib/ped/ped_server: /opt/ros/melodic/lib/libroscpp_serialization.so
/home/me/progetto_labiagi/devel/.private/ped/lib/ped/ped_server: /opt/ros/melodic/lib/librostime.so
/home/me/progetto_labiagi/devel/.private/ped/lib/ped/ped_server: /opt/ros/melodic/lib/libcpp_common.so
/home/me/progetto_labiagi/devel/.private/ped/lib/ped/ped_server: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/me/progetto_labiagi/devel/.private/ped/lib/ped/ped_server: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/me/progetto_labiagi/devel/.private/ped/lib/ped/ped_server: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/me/progetto_labiagi/devel/.private/ped/lib/ped/ped_server: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/me/progetto_labiagi/devel/.private/ped/lib/ped/ped_server: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/me/progetto_labiagi/devel/.private/ped/lib/ped/ped_server: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/me/progetto_labiagi/devel/.private/ped/lib/ped/ped_server: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/me/progetto_labiagi/devel/.private/ped/lib/ped/ped_server: CMakeFiles/ped_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/me/progetto_labiagi/build/ped/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/me/progetto_labiagi/devel/.private/ped/lib/ped/ped_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ped_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ped_server.dir/build: /home/me/progetto_labiagi/devel/.private/ped/lib/ped/ped_server

.PHONY : CMakeFiles/ped_server.dir/build

CMakeFiles/ped_server.dir/requires: CMakeFiles/ped_server.dir/src/ped_server.cpp.o.requires

.PHONY : CMakeFiles/ped_server.dir/requires

CMakeFiles/ped_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ped_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ped_server.dir/clean

CMakeFiles/ped_server.dir/depend:
	cd /home/me/progetto_labiagi/build/ped && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/me/progetto_labiagi/src/ped /home/me/progetto_labiagi/src/ped /home/me/progetto_labiagi/build/ped /home/me/progetto_labiagi/build/ped /home/me/progetto_labiagi/build/ped/CMakeFiles/ped_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ped_server.dir/depend

