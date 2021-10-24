#include "node.h"
#include "stdio.h"
#include "stdlib.h"

extern int yyparse(Node *node);

int main(void) {
    Node *root = (Node *)malloc(sizeof(Node));
    int status = yyparse(root);
    printf("MAIN DONE!");
    return 0;
}