%{
#include "y.tab.h"
#include <stdlib.h>
%}
%%
[0-9]+ {
    yylval.number = atoi(yytext); 
    return NUMBER;
}
[\t\n ] ;
"+" return(PLUS);
"-" return(MINUS);
"*" return(TIMES);
"/" return(DIVIDE);
"(" return(LEFT_PAREN);
")" return(RIGHT_PAREN);
";" return(END);
%%
int yywrap(void) {
    return 1;
}