cmake_minimum_required(VERSION 3.25)

project(AdventOfCode2022
  VERSION 1.0
  DESCRIPTION "Advent of code 2022"
  LANGUAGES CXX
  HOMEPAGE_URL "https://github.com/jastill/AdventOfCode2022.git")

add_executable(aoc
  src/main.cpp
  src/Backpack.cpp
  src/Elf.cpp)