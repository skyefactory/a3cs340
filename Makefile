SDIR = src
ODIR = obj

CC = g++
CLFLAGS=-I$(IDIR)

all: create assign3dfo301 clean
DEPS = sort.h time.h
_OBJ = main.o, sort.o, time.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

create:
	mkdir $(ODIR)

assign3dfo301: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf $(ODIR)
