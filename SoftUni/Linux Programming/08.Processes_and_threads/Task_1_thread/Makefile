CC=gcc
CFLAGS=-c -Wall -O -pthread
LDFLAGS= -std=c99
SOURCES=main.c check_input.c distance_between_city.c pow_custom.c start_calculation.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=binary

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lpthread -lm 
.cpp.o:
	$(CC) $(CFLAGS) $< -lpthread $(LDFLAGS) -o $@
clean:
	-rm -f *.o core *.core
