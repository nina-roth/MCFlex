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

#all: MCint


#MCint: $(HEADERS) $(CPP) Makefile
	#$(CC) $(CFLAGS) -o MCFLEX $(GIT_VARIABLES) -I$(CPATH) $(FFTW) MC_flex.cpp -L$(LPATH) -lm $(FFTWLIB) -lgsl -lgslcblas $(HDF5_FLAGS)
#clean:
	#rm -rf MCFLEX


# Use -DFFTW3 to use FFTW3 (instead of FFTW 2).
#
#
# Additionally use -DFFTW3_THREADS=n to use threads. This will use n threads
# UNLESS you are compiling with openmp, in which case you do not need to set n
# as it will automatically be set to omp_get_num_threads()
#
# Note you have to link to fftw3 and fftw3_threads (or fftw3_omp)
# if you are using threads

#FFTW = -DFFTW3 -DFFTW_THREADS
#FFTWLIB = -lfftw3 -lfftw3_threads

# Example for FFTW2:

#FFTW    = -DFFTW_TYPE_PREFIX=1
#FFTWLIB = -ldfftw -ldrfftw


# If you want to use HDF5, something like the following is necessary.
#
#HDF5_FLAGS = -lhdf5 -D H5_USE_16_API -DHAVE_HDF5
#
# WARNING - HDF5 has not been tested recently and in particular won't work
# with zoom simulations as the code does not support varying mass particles


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
	$(CC) $^ -o $(BIN_DIR)/$@ $(FLAGS) $(GSL_FLAGS) 

%.o: $(SRC_DIR)/%.cpp $(DEPS)
	$(CC) $(CFLAGS) $< -o $@

clean: 
	-rm $(SRC_DIR)/*.o $(BIN_DIR)/MCflex 



