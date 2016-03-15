#
# Makefile
#

# compiler to use
CC = gcc

# name for executable
EXE = fibonacci

# source file
SRC = fibonacci.c

# default target
$(EXE): Makefile
	$(CC) $(SRC) -o $(EXE)

clean:
	rm -f core $(EXE) *.o
