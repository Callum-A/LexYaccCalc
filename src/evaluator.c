#include "evaluator.h"
#include <stdio.h>

double ev(Node *root) {
    switch (root->nodeType) {
    case BINARY_OP:
        switch (root->as.binaryOp->op) {
        case '+':
            return ev(root->as.binaryOp->left) + ev(root->as.binaryOp->right);
        case '-':
            return ev(root->as.binaryOp->left) - ev(root->as.binaryOp->right);
        case '/':
            return ev(root->as.binaryOp->left) / ev(root->as.binaryOp->right);
        case '*':
            return ev(root->as.binaryOp->left) * ev(root->as.binaryOp->right);
        default:
            // Unreachable
            printf("UNRECOGNISED BINARY OP\n");
            return 0;
        }
        break;
    case NUM:
        return root->as.number->value;
    case PROGRAM: {
        int len = root->as.program->stmts->count;
        printf("Count is %d\n", len);
        for (int i = 0; i < len; i++) {
            printf("One statement evaled to %f\n",
                   ev(&root->as.program->stmts->nodes[i]));
        }
        return 0;
    }

    default:
        // Unreachable
        printf("UNRECOGNISED NODE\n");
        return 0;
    }
}