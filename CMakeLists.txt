# cmake version to be used
cmake_minimum_required( VERSION 3.0 )

# project name
project( cpp_primer )

# flags

# files

# include
include_directories( ./include ./src )

add_executable( prog ./src/main.cpp ./src/Person.cpp ./src/Sales_data.cpp ./src/Screen.cpp ./src/Window_mgr.cpp )

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )
