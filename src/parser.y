%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "evaluator.h"

extern int yylex();
extern int yyerror(Node *root, char *s);
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
%left PLUS MINUS
%left TIMES DIVIDE
%type<node> line exp term factor
%type<number> NUMBER
%parse-param { Node *root }
%%
lines: 
    | lines line;

line: exp END { $$ = $1; printf("Result: %f\n", ev($1)); }
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
    ;
%%

int yyerror(Node *root, char *s) {
    fprintf(stderr, "%s\n", s);
    return 0;
}