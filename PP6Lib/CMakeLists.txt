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
  PP6Day4Menu.hpp
  PP6Day4Menu.cpp
  PP6Day5Menu.hpp
  PP6Day5Menu.cpp
  PP6ThreeVector.hpp
  PP6ThreeVector.cpp
  PP6FourVector.hpp
  PP6FourVector.cpp
  PP6Day4MuonAnalysis.hpp
  PP6Day4MuonAnalysis.cpp
  PP6Day5MuonAnalysis.hpp
  PP6Day5MuonAnalysis.cpp
  PP6Particle.hpp
  PP6Particle.cpp
  PP6ParticleInfo.hpp
  PP6ParticleInfo.cpp
  FourVectorOld.hpp
  FourVectorOld.cpp
  ParticleOld.hpp
  ParticleOld.cpp
  PP6Cut.hpp
  )

add_library(FileReader FileReader.hpp FileReader.cpp)