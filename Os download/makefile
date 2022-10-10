
AS=nasm
ASFLAGS=-f elf64 -g 
LD=gcc -m64 -no-pie 
LDFLAGS= 
SOURCES=$(wildcard *.asm)
OBJECTS=$(SOURCES:.asm=.o)
EXECUTABLE=test 
all: $(SOURCES) $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS) 
	$(LD) $(LDFLAGS) $(OBJECTS) -o $
$(OBJECTS): $(SOURCES)
	$(AS) $(ASFLAGS) $(SOURCES)
clean:
	rm -rf *o $(EXECUTABLE)
