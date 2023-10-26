CXX = g++
# CXXFLAGS
# CPPFLAGS
# LDFLAGS


# LD_LIBRARY_PATH=/usr/lib/atlas-base/atlas solve
# TEST_LIBRARY_PATH=../lib
# ./configure  --prefix=`pwd` --with-bounds

all: main

# test_static: test_nec.c
	# gcc --static -o test_static test_nec.c -lnecpp -lstdc++ -lm -llapack  -lblas

# test_c: test_nec.o
	# gcc -o test_c -Wl,-rpath -Wl,$(TEST_LIBRARY_PATH) test_nec.o -lnecpp


#####################################################################################
#
#	The target below shows how to compile and use the nec2++ codebase
#	from within other C++ programs (GPL compatable of course!)
#

# NECPP_SRC  = ../src/c_ggrid.cpp ../src/matrix_algebra.cpp ../src/nec_ground.cpp \
#              ../src/c_evlcom.cpp ../src/c_plot_card.cpp ../src/misc.cpp \
#              ../src/nec_context.cpp ../src/nec_output.cpp ../src/c_geometry.cpp \
#              ../src/nec_exception.cpp ../src/nec_radiation_pattern.cpp \
# 	     ../src/nec_structure_currents.cpp ../src/electromag.cpp ../src/nec_results.cpp

NECPP_SRC0 = $(shell find ./Data -name '*.cpp')
NECPP_SRC1 = $(shell find ./Logic -name '*.cpp')
NECPP_SRC2 = $(shell find ./Presentation -name '*.cpp')

NECPP_SRC = $(NECPP_SRC0) $(NECPP_SRC1)  $(NECPP_SRC2)
NECPP_OBJS = $(NECPP_SRC:.cpp=.o)

SFML_LIB_DIR = /home/kaddy120/Downloads/SFML-2.6.0/lib
SFML_INCLUDE_DIR = /home/kaddy120/Downloads/SFML-2.6.0/include


   # -I/home/kaddy120/Downloads/SFML-2.6.0/include -I/home/kaddy120/workspace/Super-Pac-Man-game/game-source-code/Data -I/home/kaddy120/work
# space/Super-Pac-Man-game/game-source-code/Logic Main.cpp
CPP_SRC  = Main.cpp
CPP_OBJS = $(CPP_SRC:.cpp=.o)

# CXXFLAGS=-I ../src/ -I .. -O2 -Wall
CXXFLAGS= -std=c++20 -fpermissive -I Logic/ -I Data/ -I .
# -L$(SFML_LIB_DIR) -I$(SFML_INCLUDE_DIR) -Wall 

main: ${CPP_OBJS} ${NECPP_OBJS}
	# g++ ${CCCALLFLAGS} ${CPP_OBJS} ${NECPP_OBJS} ${CXXFLAGS} -lsfml-graphics -o main
	g++ ${CCCALLFLAGS} ${CPP_OBJS} ${NECPP_OBJS} -o game.out -lsfml-graphics -lsfml-window -lsfml-system
	# ./test_cpp

cpp_clean:
	rm -f ${CPP_OBJS} ${NECPP_OBJS} 

clean: cpp_clean
	rm -f test_cpp test_static test_c

# set env LD_LIBRARY_PATH /home/21p54/intel/compilers_and_libraries/linux/mkl/lib/intel64
