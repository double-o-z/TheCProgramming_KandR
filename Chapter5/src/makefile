IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR) -Wall -ansi -pedantic

ODIR=obj
LDIR =../lib

_DEPS = exercise5.10.h exercise5.5.h exercise5.4.h exercise5.3.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o exercise5.10.o exercise5.5.o exercise5.4.o exercise5.3.o exercise5.2.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
