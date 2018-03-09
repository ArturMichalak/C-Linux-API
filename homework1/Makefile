OBJ =  main.o ReadFile.o

all: ReadFile clean

ReadFile: $(OBJ)
	gcc $(OBJ) -o ReadFile

$(OBJ): ReadFile.h

.PHONY: clean
clean:
	rm -f *o

# włączenie trybu C99
CFLAGS=-std=c99

