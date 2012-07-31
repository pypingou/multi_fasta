CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp fasta.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=read_fasta

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o read_fasta
