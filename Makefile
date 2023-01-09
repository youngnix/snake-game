CC = clang
CFLAGS = -Wall -g
SRC = src/main.c src/renderer.c src/window.c src/game.c
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
