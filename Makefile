CC = gcc
CFLAGS = -std=c99

all: bin/NoughtsAndCrosses.exe

bin/NoughtsAndCrosses.exe: obj/main.o obj/functions.o
	$(CC) $^ -o $@

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

obj/main.o obj/functions.o: src/functions.h

clean:
	rm -f bin/*.exe obj/*.o

.PHONY: all clean