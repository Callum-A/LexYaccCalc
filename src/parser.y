%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "evaluator.h"

extern int yylex();
extern int yyerror(char *s);
extern Node *root;
%}
%union {
    struct Node *node;
    double number;
}
%start lines
%token NUMBER
%token PLUS MINUS TIMES DIVIDE
%token LEFT_PAREN RIGHT_PAREN
%token END
%token PRINT
%left PLUS MINUS
%left TIMES DIVIDE
%type<node> line exp term factor lines
%type<number> NUMBER
%%
lines: { $$ = makeProgram("PROG"); root = $$; }
    | lines line { addNodeToProgram($1, $2); }
    ;

line: exp END { $$ = $1; }
    ;

exp: term { $$ = $1; }
    | exp PLUS term { $$ = makeBinaryOp($1, $3, "+", '+'); }
    | exp MINUS term { $$ = makeBinaryOp($1, $3, "-", '-'); }
    ;

term: factor { $$ = $1; }
    | term TIMES factor { $$ = makeBinaryOp($1, $3, "*", '*'); }
    | term DIVIDE factor { $$ = makeBinaryOp($1, $3, "/", '/'); }

factor: NUMBER { $$ = makeNumber(yylval.number, "NUM"); }
    | LEFT_PAREN exp RIGHT_PAREN { $$ = $2; }
    | PRINT LEFT_PAREN exp RIGHT_PAREN { $$ = makePrint($3, "print"); }
    ;
%%

int yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
    return 0;
}