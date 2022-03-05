IDIR =../include
CC= g++
CFLAGS= -std=c++11 -Wall

## subdirectory with the files. o
ODIR=obj

_DEPS = read_data.h instruction.h memory_program.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o read_data.o instruction.o memory_program.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cc $(DEPS)
	$(CC) -w -c -o $@ $< $(CFLAGS)

simulator: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 