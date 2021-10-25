#include "evaluator.h"
#include <stdio.h>

double evBinaryOp(BinaryOp *binaryOp);
double evUnaryOp(UnaryOp *unaryOp);
void evProgram(Program *program);

double ev(Node *root) {
    switch (root->nodeType) {
    case BINARY_OP:
        return evBinaryOp(root->as.binaryOp);
    case UNARY_OP:
        return evUnaryOp(root->as.unaryOp);
    case NUM:
        return root->as.number->value;
    case PROGRAM: {
        evProgram(root->as.program);
        return 0;
    }
    case PRINT_STMT:
        printf("%f\n", ev(root->as.print->exp));
        return 0;
    default:
        // Unreachable
        printf("UNRECOGNISED NODE\n");
        return 0;
    }
}

double evBinaryOp(BinaryOp *binaryOp) {
    switch (binaryOp->op) {
    case '+':
        return ev(binaryOp->left) + ev(binaryOp->right);
    case '-':
        return ev(binaryOp->left) - ev(binaryOp->right);
    case '/':
        return ev(binaryOp->left) / ev(binaryOp->right);
    case '*':
        return ev(binaryOp->left) * ev(binaryOp->right);
    default:
        // Unreachable
        printf("UNRECOGNISED BINARY OP\n");
        return 0;
    }
}

double evUnaryOp(UnaryOp *unaryOp) {
    switch (unaryOp->op) {
    case '-':
        return -ev(unaryOp->right);
    default:
        // Unreachable
        printf("Unrecognised UNARY OP\n");
        return 0;
    }
}

void evProgram(Program *program) {
    int len = program->stmts->count;
    for (int i = 0; i < len; i++) {
        ev(&program->stmts->nodes[i]);
    }
}