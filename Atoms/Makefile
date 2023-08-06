CC=gcc
INCDIRS=-I.
OPT=-O0
CFLAGS=-Wall -Wextra -g $(INCDIRS) $(OPT)

CFILES=Atoms.c Main.c
OBJECTS=Atoms.o Main.o

EXE=Main

all: $(EXE)

$(EXE): $(OBJECTS)
$(CC): -o $@ $^

# anything.o depends on anything.c @:L.H.S, ^:R.H.S
%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm $(EXE) $(OBJECTS)