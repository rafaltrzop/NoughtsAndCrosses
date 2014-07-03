CC = gcc
CFLAGS = -std=c99

all: bin/NoughtsAndCrosses.exe

bin/NoughtsAndCrosses.exe: obj/main.o obj/view.o obj/controllers.o
	$(CC) $^ -o $@

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

obj/main.o: src/view.h src/controllers.h src/constants.h
obj/view.o: src/view.h src/constants.h
obj/controllers.o: src/controllers.h src/constants.h

clean:
	rm -f bin/*.exe obj/*.o

.PHONY: all clean