cmake_minimum_required(VERSION 3.25)

project(day1
  VERSION 1.0
  DESCRIPTION "Advent of code 2022 day 1"
  LANGUAGES CXX
  HOMEPAGE_URL "https://github.com/jastill/AdventOfCode2022.git")

add_executable(day1
  src/main.cpp
  src/Elf.cpp)