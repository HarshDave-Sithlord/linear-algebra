CC=gcc
CFLAGS=-I.
DEPS = obj.h, utils.h config.h
OBJ = main.o obj.o cntx_init.c naive_kernels.c utils.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hlasp2: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
clean:
	rm ./*.o ./*.exe hlasp2