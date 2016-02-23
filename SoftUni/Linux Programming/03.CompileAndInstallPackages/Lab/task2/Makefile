CC=gcc
CFLAGS=-c -Wall -O 
LDFLAGS= -std=c99
SOURCES=main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=largest-prime

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	-rm -f *.o core *.core
