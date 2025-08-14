CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g
LDFLAGS = -lgmp

BIN_FOLDER = executable
OBJS = $(BIN_FOLDER)/gog.o
BIN = $(BIN_FOLDER)/gog

all : $(BIN_FOLDER) $(BIN)

$(BIN_FOLDER):
	mkdir executable

$(BIN) : $(OBJS)
	$(CC) $(OBJS) -o $(BIN) $(LDFLAGS)

executable/%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf executable/*
