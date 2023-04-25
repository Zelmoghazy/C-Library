CC=gcc
INCDIRS=-I.
OPT=-O2
CFLAGS=-Wall -Wextra -g $(INCDIRS) $(OPT)

CFILES=xmlparser.c test.c
OBJECTS=xmlparser.o test.o

EXE=Main

all: $(EXE)

$(EXE): $(OBJECTS)
	$(CC) -o $@ $^

# anything.o depends on anything.c @:L.H.S, ^:R.H.S
%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm $(EXE) $(OBJECTS)