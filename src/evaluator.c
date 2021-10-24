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
            return 0;
        }
        break;
    case NUM:
        return root->as.number->value;
    default:
        // Unreachable
        return 0;
    }
}