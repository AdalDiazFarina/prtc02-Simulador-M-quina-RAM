IDIR =../include
CC= g++
CFLAGS= -std=c++11 -Wall

## subdirectory with the files. o
ODIR=obj

_DEPS = read_data.h instruction.h program_memory.h data_memory.h tape.h input_unit.h output_unit.h control_unit.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o read_data.o instruction.o program_memory.o data_memory.o tape.o input_unit.o output_unit.o control_unit.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cc $(DEPS)
	$(CC) -w -c -o $@ $< $(CFLAGS)

simulator: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 