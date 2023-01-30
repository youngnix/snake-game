CC = clang
CFLAGS = -Wall -g
SRC = src/game.c src/util.c src/keyboard.c src/food.c src/main.c src/player.c src/renderer.c src/snake.c src/window.c src/linked_list.c
OUT = output
OBJ = $(SRC:.c=.o)
LFLAGS = -lSDL2main -lSDL2 -lSDL2_image -lm
IFLAGS = -Isrc

$(OUT): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(IFLAGS) $(LFLAGS) 

clean:
	@rm -f $(OUT) $(OBJ)

.PHONY:
	clean
