CC = gcc
CFLAGS = -std=c99

all: bin/NoughtsAndCrosses.exe

bin/NoughtsAndCrosses.exe: obj/main.o
	$(CC) $^ -o $@

obj/main.o: src/main.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f bin/*.exe obj/*.o

.PHONY: all clean