CC = gcc
CFLAGS = -Wall
LDFLAGS = 
SRCFILES = ./src/*.c
TARGET = ./build/main

all: lex main

lex:
	lex -o src/lex.yy.c src/lexer.l

main:
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCFILES)

clean:
	rm -f $(TARGET)