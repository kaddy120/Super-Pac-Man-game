CXX = g++
# CXXFLAGS = 
# CPPFLAGS
# LDFLAGS = 

all: main

# store the names of all source files from Data layer
GAME_SRC0 = $(shell find ../game-source-code/Data -name '*.cpp')
# store the names of all source files, except GameLogic.cpp, from Logic layers 
GAME_SRC1 = $(shell find ./../game-source-code/Logic -name '*.cpp' | grep -v 'GameLogic.cpp')

GAME_SRC = $(GAME_SRC0) $(GAME_SRC1)  $(GAME_SRC2)
GAME_OBJS = $(GAME_SRC:.cpp=.o)

CPP_SRC  = super-pacman-tests.cpp
CPP_OBJS = $(CPP_SRC:.cpp=.o)

# compilation flags for the C++ compiler 
# This variable is not explicitly used in the Makefile, but it is used by implicit rules to compile C++ source files.
CXXFLAGS= -std=c++20 -fpermissive -Wall -I ../game-source-code/Data -I ../game-source-code/Logic/ -I /usr/include/doctest

main: ${CPP_OBJS} ${GAME_OBJS}
	 g++ ${CCCALLFLAGS} ${CPP_OBJS} ${GAME_OBJS} -o test.out 

cpp_clean:
	rm -f ${CPP_OBJS} ${GAME_OBJS} 

clean: cpp_clean
	rm -f test.out 

# set env LD_LIBRARY_PATH /home/21p54/intel/compilers_and_libraries/linux/mkl/lib/intel64
