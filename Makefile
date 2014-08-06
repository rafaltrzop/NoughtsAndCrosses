CC = gcc
CFLAGS = -std=c99

all: bin/NoughtsAndCrosses.exe

bin/NoughtsAndCrosses.exe: obj/main.o obj/view.o obj/core.o obj/game_modes.o obj/ai.o
	$(CC) $^ -o $@

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

obj/main.o: src/view.h src/core.h
obj/view.o: src/view.h
obj/core.o: src/core.h src/view.h src/game_modes.h
obj/game_modes.o: src/game_modes.h src/core.h src/view.h src/ai.h
obj/ai.o: src/ai.h

clean:
	rm -f bin/*.exe obj/*.o

.PHONY: all clean