CC=gcc
CFLAGS=-c -Wall -O 
LDFLAGS= -std=c99
SOURCES=main.c check_input.c distance_between_city.c pow_custom.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=binary

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm 
.cpp.o:
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
clean:
	-rm -f *.o core *.core
