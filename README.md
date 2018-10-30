### speed library ###

Hello everybody out there using C++.
I'm doing a (free) generic library (just a hobby, won't be big and professional like boost) for 
GNU/Linux distributions. This has been brewing since 2015, and is starting to get ready. I'd like 
any feedback on things people like/dislike in boost, as my library resembles it somewhat (same onion 
structure (due to practical reasons) among other things).  

#### Features ####

speed is composed of a set of modules and each of them has a specific purpose:

- argparse : The argparse module makes it easy to write user-friendly command-line interfaces. The program defines what arguments it requires, and argparse will figure out how to parse those out of argc and argv. The argparse module also automatically generates help, usage messages and issues errors when users give the program invalid arguments.
- containers : The containers module implement holder objects that stores a collection of other objects (its elements). They are implemented as class templates, which allows a great flexibility in the types supported as elements.
- exception : Defines the base class for all exceptions thrown by the elements of the speed library, along with several types and utilities to assist handling exceptions.
- iostream : Defines a set of resources for operate with standard input/output stream objects.
- lowlevel : Implement some resources make it easy commons lowlevel operations.
- math : This module is currently empty.
- scalars : Defines a set of resources for operate with scalars objects.
- stringutils : Defines several functions to manipulate, C strings, arrays and Strings is a generic context.
- system : Defines a set of resources to interact with the system.
- time : Defines a set of resources to do common time operations.
- type_casting : Defines some function allowing type casting.
- type_traits : Defines some type traits.

### Build ###

speed comes with a CMake build script hat can be used on a wide range of platforms.
If you don't have CMake installed already, you can download it for free from 
<http://www.cmake.org/>.

CMake works by generating native makefiles or build projects that can be used in the compiler 
environment of your choice. You can either build speed as a standalone project or it can be 
incorporated into an existing CMake build for another project.

#### Dependencies ####

In order to compile this software you have to use a C++ revision equal or highter to C++17 
(ISO/IEC 14882:2017). Also the following tools and libraries are necessary with a version equal or 
highter the specified one:
- GCC 8.1.0
- CMake 3.9
- Google Test 1.8

#### Standalone CMake Project ####

When building speed as a standalone project, the typical workflow starts with:

    mkdir build         # Create a directory to hold the build output.
    cd build
    cmake ..            # Generate native build scripts.

If you are on a \*nix system, you should now see a Makefile in the current directory.  
Just type 'sudo make install' to build and install speed.

#### Incorporating Into An Existing CMake Project ####

If you want to use speed in a project which already uses CMake, then a more robust and flexible 
approach is to build speed as part of that project directly. 
This is done by making the speed source code available to the main build and adding it using 
CMake's `add_subdirectory()` command. 
This has the significant advantage that the same compiler and linker settings are used between 
speed and the rest of your project, so issues associated with using incompatible libraries 
(eg debug/release), etc. are avoided.

### Documentation ###

If you want to generate doxygen documentation you can use `doxygen Doxyfile` command and in the 
./doc directory will be placed the result.
