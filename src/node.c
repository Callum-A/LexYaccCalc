#include "node.h"
#include <stdlib.h>

Node *makeBinaryOp(Node *left, Node *right, char *token, char op) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->nodeType = BINARY_OP;
    node->token = token;
    node->as.binaryOp = (BinaryOp *)malloc(sizeof(BinaryOp));
    node->as.binaryOp->left = left;
    node->as.binaryOp->right = right;
    node->as.binaryOp->op = op;
    return node;
}

Node *makeNumber(double value, char *token) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->nodeType = NUM;
    node->token = token;
    node->as.number = (Number *)malloc(sizeof(Number));
    node->as.number->value = value;
    return node;
}