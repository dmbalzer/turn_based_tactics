CC = gcc
SRC += src/*.c
FLG += -std=c99
FLG += -Wall
LNK += -lmingw32
LNK += -lSDL2main
LNK += -lSDL2
LNK += -lSDL2_image
LNK += -lSDL2_ttf
BIN = sdl_starter

build:
	$(CC) $(SRC) $(FLG) $(LNK) -o $(BIN)
run:
	./$(BIN)