CC = gcc

bin/NoughtsAndCrosses.exe: obj/main.o
	$(CC) $^ -o $@

obj/main.o: src/main.c
	$(CC) -c $^ -o $@

clean:
	rm -f bin/*.exe obj/*.o

.PHONY: clean