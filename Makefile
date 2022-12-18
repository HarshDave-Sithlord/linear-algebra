CC=gcc
CFLAGS=-I.
DEPS = obj.h, utils.h
OBJ = main.o obj.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hlasp2: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
clean:
	rm ./*.o ./*.exe hlasp2