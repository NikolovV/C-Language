CC=gcc
CFLAGS=-c -g -Wall -O 
LDFLAGS= -std=c99
SOURCES=main.c perimeter.c surface.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=CalcFigure

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	-rm -f *.o core *.core
