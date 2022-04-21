IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR) -Wall -ansi -pedantic

ODIR=obj
LDIR =../lib

_DEPS = exercise5.4.h exercise5.3.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = exercise5.4.o exercise5.3.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
