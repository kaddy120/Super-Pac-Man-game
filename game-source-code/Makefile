CXX = g++
# CXXFLAGS
# CPPFLAGS
LDFLAGS = -Wl,-rpath=../executables/libs/

all: main


GAME_SRC0 = $(shell find ./Data -name '*.cpp')
GAME_SRC1 = $(shell find ./Logic -name '*.cpp')
GAME_SRC2 = $(shell find ./Presentation -name '*.cpp')

GAME_SRC = $(GAME_SRC0) $(GAME_SRC1)  $(GAME_SRC2)
GAME_OBJS = $(GAME_SRC:.cpp=.o)

CPP_SRC  = Main.cpp
CPP_OBJS = $(CPP_SRC:.cpp=.o)

CXXFLAGS= -std=c++20 -fpermissive -I Logic/ -I Data/ -I . 

main: ${CPP_OBJS} ${GAME_OBJS}
	$(CXX) ${CCCALLFLAGS} ${CPP_OBJS} ${GAME_OBJS}  -o game.out -lsfml-graphics -lsfml-window -lsfml-system ${LDFLAGS} 

cpp_clean:
	rm -f ${CPP_OBJS} ${GAME_OBJS} 

clean: cpp_clean
	rm -f game.out

# set env LD_LIBRARY_PATH /home/21p54/intel/compilers_and_libraries/linux/mkl/lib/intel64
