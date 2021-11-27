cmake_minimum_required(VERSION 3.20)
project(Tournoi)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE DATA src/*)
add_executable(Tournoi ${DATA})
