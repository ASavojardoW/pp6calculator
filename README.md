pp6calculator - A simple command line calculator
================================================
This is the README for the pp6calculator project, part of the MPAGS PP6
course on software development with C++.

Authors
-------
- Antonino Savojardo

License
-------
pp6calculator is distributed under the terms of the Boost Software License.


Installation
============
Prerequisites
-------------
- Unix operating system (Windows OS should work, but is not tested)
- C++98/11 compiler (`g++`/`clang++` tested)
- [CMake](http://www.cmake.org) build tool, version 2.8 or higher

Building pp6calculator
----------------------
We recommend the following sequence of steps to build `pp6calculator` using
CMake and UNIX Makefiles:

1. Create a build directory parallel to the directory holding this README,
e.g.

        $ ls
        pp6calculator.git
        $ mkdir pp6calculator.build

2. Change into the build directory and run `cmake`, pointing it to the source
directory (i.e., the directory holding this README.

3. Run `make` using the freshly generated Makefile:

        $ make
        Scanning dependencies of target pp6calculator
        [ 50%] Building CXX object CMakeFiles/pp6calculator.dir/pp6calculator.cpp.o
        [100%] Building CXX object CMakeFiles/pp6calculator.dir/PP6Lib/PP6Math.cpp.o
        Linking CXX executable pp6calculator
        [100%] Built target pp6calculator
        $
        
    The build should complete without warning or error.
    
4. You can simply run `pp6calculator` direct from the build directory

        $ ./pp6calculator

    At present, pp6calculator does not support installation.