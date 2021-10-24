CC = gcc
CFLAGS = -Wall
LDFLAGS = 
SRCFILES = ./src/*.c
TARGET = ./build/main
LEXOUT = ./src/lex.yy.c
YACCOUT = ./src/y.tab.c ./src/y.tab.h

all: yacc lex main

lex:
	lex -o src/lex.yy.c src/lexer.l

yacc:
	yacc -b ./src/y -d src/parser.y

main:
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCFILES)

clean:
	rm -f $(TARGET) $(LEXOUT) $(YACCOUT)