CC = gcc

all: bin/NoughtsAndCrosses.exe

bin/NoughtsAndCrosses.exe: obj/main.o
	$(CC) $^ -o $@

obj/main.o: src/main.c
	$(CC) -c $^ -o $@

clean:
	rm -f bin/*.exe obj/*.o

.PHONY: all clean