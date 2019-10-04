CC = gcc
CFLAGS = -g -Wall -std=c99
LDFLAGS = -lm -lgame -L.

all : recolor_text

recolor_text : recolor_text.o libgame.a
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@ 

recolor_text.o : recolor_text.c game.h game_io.h

libgame.a : game_io.o game.o
	ar -cr $@ $^

.PHONY : clean
clean :
	rm -f libgame.a recolor_text recolor_text.o