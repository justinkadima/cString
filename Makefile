#my makefile

PROG=mine
EXT=c

CC=gcc
CFLAGS=-Wall


LD=gcc
LFLAGS=


SOURCES=$(shell find *.$(EXT))
OBJ=$(SOURCES:.$(EXT)=.o)


all:$(PROG)

$(PROG):$(OBJ)
	$(LD) $(LFLAGS) $(OBJ) -o $(PROG)


%.o:%.$(EXT)
	$(CC) $(CFLAGS) -c $<


depend:
	$(CC) -MM *.c >$(PROG).depend

include $(PROG).depend

cleano:
	rm -f $(OBJ)

clean:
	rm -f $(OBJ) $(PROG)
	

