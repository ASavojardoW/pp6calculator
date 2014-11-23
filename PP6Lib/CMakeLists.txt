# - CMake script for pp6lib library
#
add_library(pp6lib STATIC 
  PP6Math.hpp 
  PP6Math.cpp
  PP6Day1Menu.hpp 
  PP6Day1Menu.cpp
  PP6Day2Menu.hpp 
  PP6Day2Menu.cpp
  PP6Day3Menu.hpp 
  PP6Day3Menu.cpp
  FourVector.hpp
  FourVector.cpp
  Particle.hpp
  Particle.cpp
  )
add_library(FileReader FileReader.hpp FileReader.cpp)
