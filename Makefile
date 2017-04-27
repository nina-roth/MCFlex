# Reasonably sensible defaults
CC    	= g++
C		= gcc
CFLAGS	= -Wall -g -O3 -std=c++14  -fdiagnostics-color=auto
CPATH 	= /opt/local/include/
LPATH   = /opt/local/lib
GSL_FLAGS = -lgsl -lgslcblas
FLAGS = -lm
INC_DIR = include   
SRC_DIR = src
BIN_DIR = bin

# Some customizations for known systems

HOST	= $(shell if [ `which scutil 2>/dev/null` ]; then scutil --get ComputerName | cut -c1-5; else hostname | cut -c1-5 ; fi )
GIT_VERSION = $(shell git rev-parse --short HEAD)
GIT_MODIFIED = $(shell git ls-files -m | tr "\n" " ")
GIT_VARIABLES = -DGIT_VERSION='"$(GIT_VERSION)"' -DGIT_MODIFIED='"$(GIT_MODIFIED)"'

ifeq ($(HOST), Airy)
	CC      = /opt/local/bin/g++
	#FFTW    = -DFFTW_TYPE_PREFIX=1
    #FFTWLIB = -ldfftw -ldrfftw
endif

SRCS = $(SRC_DIR)/*.cpp
DEPS = $(INC_DIR)/*.h
#OBJS = $(OBJ_DIR)/*.o

all: MCflex

MCflex: $(SRC_DIR)/MC_flex.o
	$(CC) $^ -o $(BIN_DIR)/$@ $(FLAGS) $(GSL_FLAGS) $(GIT_VARIABLES)

%.o: $(SRC_DIR)/%.cpp $(DEPS)
	$(CC) $(CFLAGS) $< -o $@ $(GIT_VARIABLES)

clean: 
	-rm $(SRC_DIR)/*.o $(BIN_DIR)/MCflex 



