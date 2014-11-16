# - Main CMake script for pp6calculator
#
# - Require latest generation of CMake
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# - Declare the project
project(pp6calculator)

# - Tell compiler where to find headers
include_directories(PP6Lib)

# - Add the PP6 Lib
add_subdirectory(PP6Lib)

# - Add the pp6calculator program
add_executable(pp6calculator pp6calculator.cpp )

# - Link pp6calculator to the pp6library
target_link_libraries(pp6calculator pp6lib)
target_link_libraries(pp6calculator FileReader)

# - Install pp6calculator to the bin subdirectory of CMAKE_INSTALL_PREFIX
install(TARGETS pp6calculator DESTINATION bin)

# - Package pp6calculator sources and executable
include(CPack)