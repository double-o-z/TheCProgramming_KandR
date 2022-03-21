IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR) -Wall -ansi -pedantic

ODIR=obj
LDIR =../lib

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = exercise4_1.o exercise4_2.o exercise4_3_8.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
