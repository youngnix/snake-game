CC = clang
CFLAGS = -Wall -g
SRC = src/game.c src/keyboard.c src/fruit.c src/main.c src/player.c src/renderer.c src/snake.c src/window.c
OUT = output
OBJ = $(SRC:.c=.o)
LFLAGS = -lSDL2main -lSDL2
IFLAGS = -Isrc

$(OUT): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(IFLAGS) $(LFLAGS) 

clean:
	@rm -f $(OUT) $(OBJ)

.PHONY:
	clean
