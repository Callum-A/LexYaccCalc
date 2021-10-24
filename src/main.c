#include "evaluator.h"
#include "node.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct yy_buffer_state *YY_BUFFER_STATE;
extern YY_BUFFER_STATE yy_scan_string(char *str);
extern void yy_delete_buffer(YY_BUFFER_STATE buffer);
extern int yyparse();

Node *root;

int main(void) {
    char string[] = "print(-50);print(10 / 2);";
    YY_BUFFER_STATE buffer = yy_scan_string(string);
    yyparse();
    yy_delete_buffer(buffer);
    ev(root);
    return 0;
}